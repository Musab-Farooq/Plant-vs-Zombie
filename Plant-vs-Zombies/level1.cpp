#include "level1.h"

// Function to create the background for Level 1
void createBack1(RenderWindow& window) {
    // Load the background image
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

// Default constructor for Level 1
level1::level1() : levels()
{
}

// Function to set up the zombie factory for Level 1
void level1::setzombiefactory()
{
    // Create a zombie factory for Level 1 with level number 1
    zombieFactory ZombArmy(1);

    // Create and deploy the zombie army for Level 1
    ZombArmy.armyCreation();

    // Set the zombie factory for Level 1 to the created factory
    this->z1 = ZombArmy;
}

// Function to draw the background for Level 1
void level1::drawbackground(sf::RenderWindow& window)
{
    // Call the function to create and draw the Level 1 background
    createBack1(window);
}
