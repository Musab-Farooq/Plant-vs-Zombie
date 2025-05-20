#include "startingscreen.h"


startingscreen::startingscreen()
{
}

startingscreen::startingscreen(string p,int num):screens(p,num)
{
}

bool startingscreen::setbutton(sf::RenderWindow& window, sf::Event event, bool check, sf::Mouse mouse)
{
    // Get the current mouse position
    int posx = sf::Mouse::getPosition(window).x;
    int posy = sf::Mouse::getPosition(window).y;

    // Check if the mouse position is within the button's boundaries
    if (posx >= changebutton(0).getposX() && posx <= changebutton(0).getposX() + changebutton(0).getsizeX() && posy >= changebutton(0).getposY() && posy <= changebutton(0).getposY() + changebutton(0).getsizeY())
    {
        // Set button properties when hovered over
        changebutton(0).setbutton("Images/button.png", 350, 150, 480, 550, 0, sf::Color::White);

        // Check if the mouse button is pressed
        if (event.type == sf::Event::MouseButtonPressed)
        {
            check = false; // Set check variable to false
        }
    }
    else
    {
        // Set default button properties
        changebutton(0).setbutton("Images/button.png", 300, 100, 500, 600, 0, sf::Color::White);
    }
    return check; // Return the updated check variable
}

