#include "instructionscreen.h"

// Default constructor
instructionscreen::instructionscreen()
{
}

// Constructor with parameters to set the path and button number
instructionscreen::instructionscreen(string p, int num) : screens(p, num)
{
}

void instructionscreen::setinstructions(sf::RenderWindow& window)
{
    sf::Font font;
    font.loadFromFile("Fonts/arial.ttf");
    sf::Text instructions;
    instructions.setFont(font);
    instructions.setCharacterSize(30);
    instructions.setFillColor(sf::Color::Red);
    instructions.setOutlineColor(sf::Color::Black);
    instructions.setOutlineThickness(5);
    instructions.setStyle(sf::Text::Bold);
    instructions.setPosition(400, 150);
    instructions.setLineSpacing(1.2);
    instructions.setString("Hello! I am FAST the owner of the garden.\nZombies have attacked our House. Zombies\nwant to eat our brains. Only you can save us.\nSelect plants from my plant inventory to kill the\nzombies. A simple Zombie and flying zombie is\nkilled by a 2 bullets, football zombie is killed\nby 4 bullets, dancing zombies is also killed by\n2 bullets but they can bring more zombies\nwith them. You can press P to pause game\n                          Best of Luck!\n");
    window.draw(instructions);
}

// Function to handle button interactions in the instruction screen
bool instructionscreen::setbutton(sf::RenderWindow& window, sf::Event event, bool check, sf::Mouse mouse)
{
    // Get the mouse position
    int posx = sf::Mouse::getPosition(window).x;
    int posy = sf::Mouse::getPosition(window).y;

    // Check if the mouse is over the button area
    if (posx >= 70 && posx <= 282 && posy >= 676 && posy <= 733)
    {
        // Set button properties for hover state
        changebutton(0).setbutton("Images/backbuttoninstruction.png", 350, 150, 10, 620, 0, sf::Color::White);

        // Check if the mouse button is pressed
        if (event.type == sf::Event::MouseButtonPressed)
        {
            check = true; // Set the check flag to true
        }
    }
    else
    {
        // Set button properties for default state
        changebutton(0).setbutton("Images/backbuttoninstruction.png", 300, 100, 20, 650, 0, sf::Color::White);
    }

    return check; // Return the updated check flag
}
