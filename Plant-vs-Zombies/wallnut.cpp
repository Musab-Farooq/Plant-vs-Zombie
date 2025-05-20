#include "wallnut.h"

// Constructor for wallnut object
wallnut::wallnut(string address, int x, int y) : plant(address, x, y)
{
    // No additional initialization needed
}

// Method to collect sun (returns 0 for wallnut)
int wallnut::collectSun(int x, int y, RenderWindow& window)
{
    return 0; // Wallnut doesn't produce sun, so return 0
}

// Method to handle wallnut functionality
void wallnut::plantFunctionality(const Event& event, RenderWindow& w)
{
    if (exists) {
        drawPlant(w); // Draw wallnut plant on window if it exists
    }
    if (!pause) { // If game is not paused
        decreaseLife(); // Decrease wallnut's life over time
        // Change wallnut texture based on elapsed time
        if (plantClock.getElapsedTime().asSeconds() < 1) {
            row += 3;
            plantTexture.loadFromFile("Images/wallnut.png");
        }
        else if (plantClock.getElapsedTime().asSeconds() < 2) {
            row += 3;
            plantTexture.loadFromFile("Images/wallnut1.png");
        }
        else if (plantClock.getElapsedTime().asSeconds() < 3) {
            row += 3;
            plantTexture.loadFromFile("Images/wallnut2.png");
        }
        else if (plantClock.getElapsedTime().asSeconds() < 4) {
            row += 3;
            plantTexture.loadFromFile("Images/wallnut3.png");
        }
        else {
            plantTexture.loadFromFile("Images/wallnut.png");
        }
        plantSprite.setPosition(row, column); // Update plant sprite position
    }
}

// Method to draw wallnut plant on window
void wallnut::drawPlant(RenderWindow& window)
{
    window.draw(plantSprite); // Draw wallnut plant sprite on window
}
