#include "screens.h"

// Default constructor for screens
screens::screens()
{
    this->buttonnum = 0;
    this->pathscreen = "";
    this->buttons = NULL;
}

// Parameterized constructor for screens
screens::screens(string p, int num)
{
    this->pathscreen = p;
    this->buttonnum = num;
    buttons = new button[num];
}

// Function to set the path of the screen image
void screens::setpath(string p)
{
    this->pathscreen = p;
}

// Function to change a specific button in the screen
button& screens::changebutton(int position)
{
    return this->buttons[position];
}

// Function to draw the screen and its buttons
void screens::drawscreen(sf::RenderWindow& window)
{
    // Load the screen image
    sf::Image map_image;
    map_image.loadFromFile(pathscreen);
    sf::Texture map;
    map.loadFromImage(map_image);
    sf::Sprite s_map;
    s_map.setTexture(map);
    s_map.setPosition(0, 0);
    window.draw(s_map);

    // Draw each button on the screen
    for (int i = 0; i < buttonnum; i++) {
        buttons[i].drawbutton(window);
    }
}
