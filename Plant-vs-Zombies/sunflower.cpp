#include "sunflower.h"

// Constructor for sunflower object
sunflower::sunflower(string address, int x, int y) : plant(address, x, y)
{
    sunExist = false; // Set initial state of sun existence to false
    sunTexture.loadFromFile("Images/sun.png"); // Load sun texture from file
    sunSprite.setTexture(sunTexture); // Set sun sprite texture
    sunSprite.setTextureRect(IntRect(0, 0, 42, 42)); // Set sun sprite rectangle
    plantSprite.setPosition(x, y); // Set position of plant sprite
    collectable = true; // Set plant as collectable
}

// Default constructor for sunflower object
sunflower::sunflower() : plant()
{
    sunExist = false; // Set initial state of sun existence to false
    sunTexture.loadFromFile("Images/sun.png"); // Load sun texture from file
    sunSprite.setTexture(sunTexture); // Set sun sprite texture
    sunSprite.setTextureRect(IntRect(0, 0, 42, 42)); // Set sun sprite rectangle
}

// Method to make sun appear after a certain time interval
void sunflower::makeSun(Clock& cl)
{
    if (cl.getElapsedTime().asSeconds() < 2) // Check if time elapsed is less than 3 seconds
        return; // If so, return without making sun

    cl.restart(); // Restart clock
    sunExist = true; // Set sun existence to true
}

// Method to draw plant sprite on the window
void sunflower::drawPlant(RenderWindow& window)
{
    window.draw(plantSprite); // Draw plant sprite on the window
}

// Method to change plant texture based on sun existence
void sunflower::changeTexture()
{
    if (sunExist) { // If sun exists
        plantTexture.loadFromFile("Images/sunflowerActive2.png"); // Load active sunflower texture
        plantSprite.setTexture(plantTexture); // Set plant sprite texture
    }
    else { // If sun doesn't exist
        plantTexture.loadFromFile("Images/sunflower.png"); // Load default sunflower texture
        plantSprite.setTexture(plantTexture); // Set plant sprite texture
    }
}

// Method to collect sun if clicked on
int sunflower::collectSun(int x, int y, RenderWindow& window)
{
    if (sunExist) { // If sun exists
        if (x < row + 50 && x >row - 10 && y < column + 50 && y > column - 10) { // Check if clicked on sun
            sunExist = false; // Set sun existence to false
            plantClock.restart(); // Restart plant clock
            return 50; // Return score for collecting sun
        }
    }
    return 0; // Return 0 if sun not collected
}

// Method to handle plant functionality
void sunflower::plantFunctionality(const Event& event, RenderWindow& w)
{
    if (exists) { // If plant exists
        w.draw(plantSprite); // Draw plant sprite on the window
        if (!pause) { // If game is not paused
            decreaseLife(); // Decrease plant life
            if (sunExist) { // If sun exists
                plantTexture.loadFromFile("Images/sunflowerActive2.png"); // Load active sunflower texture
                plantSprite.setTexture(plantTexture); // Set plant sprite texture
            }
            else { // If sun doesn't exist
                plantTexture.loadFromFile("Images/sunflower.png"); // Load default sunflower texture
                plantSprite.setTexture(plantTexture); // Set plant sprite texture
            }

            if (this->plantClock.getElapsedTime().asSeconds() < 3) // Check if time elapsed is less than 3 seconds
                return; // If so, return

            plantClock.restart(); // Restart plant clock
            sunExist = true; // Set sun existence to true
        }
    }
}
