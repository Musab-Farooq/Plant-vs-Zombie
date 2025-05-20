#include "Exitscreen.h"

// Default constructor
exitscreen::exitscreen()
{
}

// Parameterized constructor
exitscreen::exitscreen(string p, int num) :screens(p, num)
{
}

// Method to set the behavior of the exit button on the exit screen
bool exitscreen::setbutton(sf::RenderWindow& window, sf::Event event, bool check, sf::Mouse mouse)
{
	// Get the current mouse position
	int posx = sf::Mouse::getPosition(window).x;
	int posy = sf::Mouse::getPosition(window).y;

	// Check if the mouse is within the exit button's boundaries
	if (posx >= 70 && posx <= 282 && posy >= 676 && posy <= 733)
	{
		// Change the appearance of the button when hovered
		changebutton(0).setbutton("Images/backbuttoninstruction.png", 350, 150, 10, 620, 0, sf::Color::White);

		// Check if the mouse button is pressed
		if (event.type == sf::Event::MouseButtonPressed)
		{
			check = true; // Set check to true to indicate button press
		}
	}
	else
	{
		// Reset button appearance when not hovered
		changebutton(0).setbutton("Images/backbuttoninstruction.png", 300, 100, 20, 650, 0, sf::Color::White);
	}

	return check; // Return the updated check value
}
