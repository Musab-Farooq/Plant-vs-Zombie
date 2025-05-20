#include "level2.h"

// Function to create the background for Level 2
void createBack2(RenderWindow& window) {
    // Load the background image specific to Level 2
    Image map_image;
    map_image.loadFromFile("Images/level1background.jpeg");

    // Create a texture and set it to the loaded image
    Texture map;
    map.loadFromImage(map_image);

    // Create a sprite and set its texture and position
    Sprite s_map;
    s_map.setTexture(map);
    s_map.setPosition(0, 0);

    // Draw the background sprite to the window
    window.draw(s_map);
}

// Default constructor for Level 2
level2::level2()
{
}

// Function to set up the zombie factory for Level 2
void level2::setzombiefactory()
{
    // Create a zombie factory for Level 2 with level number 2
    zombieFactory ZombArmy(2);

    // Create and deploy the zombie army for Level 2
    ZombArmy.armyCreation();

    // Set the zombie factory for Level 2 to the created factory
    this->z1 = ZombArmy;
}

// Function to draw the background for Level 2
void level2::drawbackground(sf::RenderWindow& window)
{
    // Call the function to create and draw the Level 2 background
    createBack2(window);
}
