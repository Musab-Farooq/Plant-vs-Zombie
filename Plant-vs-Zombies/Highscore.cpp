#include "Highscore.h"

// Default constructor
score::score()
{
}

// Constructor with parameters to set the path and button number
score::score(string p, int num) : screens(p, num)
{
}

// Function to handle button interactions in the highscore screen
bool score::setbutton(sf::RenderWindow& window, sf::Event event, bool check, sf::Mouse mouse)
{
    // Get the mouse position
    int posx = sf::Mouse::getPosition(window).x;
    int posy = sf::Mouse::getPosition(window).y;

    // Check if the mouse is over the button area
    if (posx >= 70 && posx <= 282 && posy >= 676 && posy <= 733)
    {
        // Set button properties for hover state
        changebutton(0).setbutton("Images/backbuttoninstruction.png", 350, 150, -10, 620, 0, sf::Color::White);

        // Check if the mouse button is pressed
        if (event.type == sf::Event::MouseButtonPressed)
        {
            check = true; // Set the check flag to true
        }
    }
    else
    {
        // Set button properties for default state
        changebutton(0).setbutton("Images/backbuttoninstruction.png", 300, 100, -5, 650, 0, sf::Color::White);
    }

    return check; // Return the updated check flag
}
