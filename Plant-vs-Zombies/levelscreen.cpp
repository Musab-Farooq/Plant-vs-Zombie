#include "levelscreen.h"

levelscreen::levelscreen()
{
}

levelscreen::levelscreen(string p, int num) : screens(p, num)
{
}

bool levelscreen::setbutton(sf::RenderWindow& window, sf::Event event, bool check, sf::Mouse mouse)
{
    int posx = sf::Mouse::getPosition(window).x;
    int posy = sf::Mouse::getPosition(window).y;

    // Check if mouse is over level 4 button
    if (posx >= 710 && posx <= 810 && posy >= 100 && posy <= 250)
    {
        changebutton(3).setbutton("Images/level4.png", 150, 200, 690, 80, 0, sf::Color::White);
    }
    else
    {
        changebutton(3).setbutton("Images/level4.png", 100, 150, 710, 100, 0, sf::Color::White);
    }

    // Check if mouse is over level 5 button
    if (posx >= 880 && posx <= 980 && posy >= 100 && posy <= 250)
    {
        changebutton(4).setbutton("Images/level5.png", 150, 200, 880, 80, 0, sf::Color::White);
    }
    else
    {
        changebutton(4).setbutton("Images/level5.png", 100, 150, 880, 100, 0, sf::Color::White);
    }

    // Check if mouse is over level 6 button
    if (posx >= 1050 && posx <= 1150 && posy >= 100 && posy <= 250)
    {
        changebutton(5).setbutton("Images/level6.png", 150, 200, 1050, 80, 0, sf::Color::White);
    }
    else
    {
        changebutton(5).setbutton("Images/level6.png", 100, 150, 1050, 100, 0, sf::Color::White);
    }

    // Set the back button
    changebutton(6).setbutton("Images/backbuttoninstruction.png", 300, 100, 20, 650, 0, sf::Color::Transparent);
    if (posx <= 85 && posy >= 682 && event.type == sf::Event::MouseButtonPressed)
    {
        check = true;
    }

    return check;
}

bool levelscreen::setlevel1(sf::RenderWindow& window, sf::Event event, bool check, sf::Mouse mouse)
{
    int posx = sf::Mouse::getPosition(window).x;
    int posy = sf::Mouse::getPosition(window).y;

    // Check if mouse is over level 1 button
    if (posx >= 200 && posx <= 300 && posy >= 100 && posy <= 250)
    {
        changebutton(0).setbutton("Images/level1.png", 150, 200, 180, 80, 0, sf::Color::White);
        if (event.type == sf::Event::MouseButtonPressed)
        {
            check = true;
        }
    }
    else
    {
        changebutton(0).setbutton("Images/level1.png", 100, 150, 200, 100, 0, sf::Color::White);
    }

    return check;
}

bool levelscreen::setlevel2(sf::RenderWindow& window, sf::Event event, bool check, sf::Mouse mouse)
{
    int posx = sf::Mouse::getPosition(window).x;
    int posy = sf::Mouse::getPosition(window).y;

    // Check if mouse is over level 2 button
    if (posx >= 370 && posx <= 470 && posy >= 100 && posy <= 250)
    {
        changebutton(1).setbutton("Images/level2.png", 150, 200, 350, 80, 0, sf::Color::White);
        if (event.type == sf::Event::MouseButtonPressed)
        {
            check = true;
        }
    }
    else
    {
        changebutton(1).setbutton("Images/level2.png", 100, 150, 370, 100, 0, sf::Color::White);
    }

    return check;
}

bool levelscreen::setlevel3(sf::RenderWindow& window, sf::Event event, bool check, sf::Mouse mouse)
{
    int posx = sf::Mouse::getPosition(window).x;
    int posy = sf::Mouse::getPosition(window).y;

    // Check if mouse is over level 3 button
    if (posx >= 540 && posx <= 640 && posy >= 100 && posy <= 250)
    {
        changebutton(2).setbutton("Images/level3.png", 150, 200, 520, 80, 0, sf::Color::White);
        if (event.type == sf::Event::MouseButtonPressed)
        {
            check = true;
        }
    }
    else
    {
        changebutton(2).setbutton("Images/level3.png", 100, 150, 540, 100, 0, sf::Color::White);
    }

    return check;
}
