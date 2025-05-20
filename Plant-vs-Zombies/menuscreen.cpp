#include "menuscreen.h"

mainmenu::mainmenu()
{
}

mainmenu::mainmenu(string p, int num) : screens(p, num)
{
}

bool mainmenu::setlevel(sf::RenderWindow& window, sf::Event event, bool check, sf::Mouse mouse)
{
    int posx = sf::Mouse::getPosition(window).x;
    int posy = sf::Mouse::getPosition(window).y;

    // Check if mouse is over the level button
    if (posx >= 700 && posx <= 1266 && posy >= 102 && posy <= 245)
    {
        changebutton(0).setbutton("Images/level.png", 730, 480, 660, -90, 5, sf::Color::White);
        if (event.type == sf::Event::MouseButtonPressed)
        {
            check = false;
        }
    }
    else
    {
        changebutton(0).setbutton("Images/level.png", 690, 440, 660, -70, 5, sf::Color::White);
    }

    // Check if mouse is over the exit button
    if (posx >= 726 && posx <= 1160 && posy >= 460 && posy <= 550)
    {
        changebutton(3).setbutton("Images/exitbutton.png", 560, 370, 690, 290, 10, sf::Color::White);
        if (event.type == sf::Event::MouseButtonPressed)
        {
            window.close();
        }
    }
    else
    {
        changebutton(3).setbutton("Images/exitbutton.png", 545, 310, 700, 320, 10, sf::Color::White);
    }

    // Check if mouse is over the zombie button
    if (posx <= 223 && posy >= 600)
    {
        changebutton(4).setbutton("Images/zombie.png", 350, 350, 130, 380, 40, sf::Color::White);
    }
    else
    {
        changebutton(4).setbutton("Images/zombie.png", 300, 300, 80, 420, 35, sf::Color::White);
    }

    return check;
}

bool mainmenu::setinstructions(sf::RenderWindow& window, sf::Event event, bool check, sf::Mouse mouse)
{
    int posx = sf::Mouse::getPosition(window).x;
    int posy = sf::Mouse::getPosition(window).y;

    // Check if mouse is over the instructions button
    if (posx >= 712 && posx <= 1215 && posy <= 370 && posy >= 250)
    {
        changebutton(1).setbutton("Images/instruction.png", 670, 420, 660, 80, 7, sf::Color::White);
        if (event.type == sf::Event::MouseButtonPressed)
        {
            check = false;
        }
    }
    else
    {
        changebutton(1).setbutton("Images/instruction.png", 630, 380, 675, 100, 7, sf::Color::White);
    }

    return check;
}

bool mainmenu::sethighscore(sf::RenderWindow& window, sf::Event event, bool check, sf::Mouse mouse)
{
    int posx = sf::Mouse::getPosition(window).x;
    int posy = sf::Mouse::getPosition(window).y;

    // Check if mouse is over the highscore button
    if (posx >= 711 && posx <= 1175 && posy <= 460 && posy >= 365)
    {
        changebutton(2).setbutton("Images/highscore.png", 600, 400, 670, 190, 8, sf::Color::White);
        if (event.type == sf::Event::MouseButtonPressed)
        {
            check = false;
        }
    }
    else
    {
        changebutton(2).setbutton("Images/highscore.png", 580, 340, 680, 220, 8, sf::Color::White);
    }

    return check;
}
