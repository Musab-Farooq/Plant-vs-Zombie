#include "game.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "plant.h"
#include "plantFactory.h"
#include "bullet.h"
#include "sunflower.h"
#include "peaPlant.h"
#include "wallnut.h"
#include "cherrybomb.h"
#include "repeater.h"
#include "snowPea.h"
#include "bullet.h"
#include "Zombie.h"
#include "normalZombie.h"
#include "dancingZombie.h"
#include "footballZombie.h"
#include "flyingZombie.h"
#include "zombieFactory.h"
#include "Textbox.h"
#include "startingscreen.h"
#include "menuscreen.h"
#include "levelscreen.h"
#include "instructionscreen.h"
#include "Highscore.h"
#include "levels.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "Exitscreen.h"


using namespace sf;
using namespace std;

Plant_vs_Zombies::Plant_vs_Zombies()
{
}

void Plant_vs_Zombies::play()
{
    // Create a fullscreen window for the game
    RenderWindow window(VideoMode::getFullscreenModes()[0], "Plants Vs Zombies", Style::Fullscreen);


    // Load game icon
    Image icon;
    if (!icon.loadFromFile("Images/icon.png"))
    {
        return; // Return an error code if icon loading fails
    }
    window.setIcon(32, 32, icon.getPixelsPtr());

    // Create clocks for timing
    Clock timeMoney;
    Clock clock;
    srand(time(0)); // Seed for random number generation

    // Create instances of game levels
    levels* levelnumber1 = new level1();
    levelnumber1->setzombiefactory();

    levels* levelnumber2 = new level2;
    levelnumber2->setzombiefactory();

    levels* levelnumber3 = new level3;
    levelnumber3->setzombiefactory();

    // Initialize game screens
    startingscreen startingscreen("Images/backwindow.png", 1);
    mainmenu menuscreen("Images/mainmenu.png", 5);
    levelscreen levelscreen("Images/levelmenu.png", 7);
    instructionscreen instructionscreen("Images/instructionpage.png", 1);
    score highscore("Images/score.png", 1);
    exitscreen winscreen("Images/win.png", 1);
    exitscreen gameover("Images/gameover.png", 1);

    // Initialize variables for game state and UI
    bool exist = true;
    bool check1 = true;
    bool check2 = true;
    bool check3 = true;
    bool level1 = false;
    bool level2 = false;
    bool level3 = false;
    sf::Mouse mouse;

    // Initialize text box for user input
    Textbox text("Images/textbox.png", 500, 500, 150, 100, 0, sf::Color::White);
    text.settext(15, sf::Color::Black, 235, 355);
    bool textboxexist = true;
    bool ok = true;
    bool cancel = true;

    // Main game loop
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        float moneyTime = timeMoney.getElapsedTime().asSeconds();

        time = time / 800; // Time normalization
        Event event;

        // Event handling loop
        while (window.pollEvent(event))
        {
            // Close window if requested
            if (event.type == Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }

            // Handle events based on game state and user input
            if (exist) {
                exist = startingscreen.setbutton(window, event, exist, mouse);
            }
            // Handle main menu events
            else if (check1 && check2 && check3) {
                check1 = menuscreen.setlevel(window, event, check1, mouse);
                check2 = menuscreen.setinstructions(window, event, check2, mouse);
                check3 = menuscreen.sethighscore(window, event, check3, mouse);
                cancel = true;
            }
            // Handle text box events
            else if (ok && cancel && !check1) {
                cancel = text.textboxsetcacel(event, cancel, mouse, window);
                ok = text.textboxsetok(event, ok, mouse, window);
            }
            // Handle level selection events
            else if (!cancel) {
                check1 = true;
            }
            // Handle game level events
            else if (!check1 && !ok && !level1 && !level2 && !level3) {
                check1 = levelscreen.setbutton(window, event, check1, mouse);
                level1 = levelscreen.setlevel1(window, event, level1, mouse);
                level2 = levelscreen.setlevel2(window, event, level2, mouse);
                level3 = levelscreen.setlevel3(window, event, level3, mouse);
            }
            // Handle instruction screen events
            else if (!check2) {
                check2 = instructionscreen.setbutton(window, event, check2, mouse);
            }
            // Handle high score screen events
            else if (!check3) {
                check3 = highscore.setbutton(window, event, check3, mouse);
            }

            // Handle events specific to each game level
            if (level1) {
                levelnumber1->gameloop(event, window);
                level1 = levelnumber1->exitbutton(event, window, mouse, level1);
                level1 = winscreen.setbutton(window, event, level1, mouse);
                level1 = gameover.setbutton(window, event, level1, mouse);
            }
            else if (level2) {
                levelnumber2->gameloop(event, window);
                level2 = levelnumber2->exitbutton(event, window, mouse, level2);
                level2 = winscreen.setbutton(window, event, level2, mouse);
                level2 = gameover.setbutton(window, event, level2, mouse);
            }
            else if (level3) {
                levelnumber3->gameloop(event, window);
                level3 = levelnumber3->exitbutton(event, window, mouse, level3);
                level3 = winscreen.setbutton(window, event, level3, mouse);
                level3 = gameover.setbutton(window, event, level3, mouse);
            }
        }

        // Draw different game screens based on game state and user actions
        if (exist) {
            startingscreen.drawscreen(window);
        }
        else if (check1 && check2 && check3) {
            menuscreen.drawscreen(window);
            cancel = true;
        }
        else if (ok && cancel && !check1) {
            text.writetext(event);
            text.drawbutton(window);
            text.drawtext(window);
            text.save(event, mouse, window);
        }
        else if (!cancel) {
            check1 = true;
        }
        else if (!check1 && !ok && !level1 && !level2 && !level3) {
            levelscreen.drawscreen(window);
        }
        else if (level1) {
            levelnumber1->drawbackground(window);
            levelnumber1->draw(event, window);
        }
        else if (level2) {
            levelnumber2->drawbackground(window);
            levelnumber2->draw(event, window);
        }
        else if (level3) {
            levelnumber3->drawbackground(window);
            levelnumber3->draw(event, window);
        }
        else if (levelnumber1->gameover() || levelnumber2->gameover() || levelnumber3->gameover()) {
            gameover.drawscreen(window);
        }
        else if (levelnumber1->wingame() || levelnumber2->wingame() || levelnumber3->wingame()) {
            winscreen.drawscreen(window);
        }
        else if (!check2) {
            instructionscreen.drawscreen(window);
            instructionscreen.setinstructions(window);
        }
        else if (!check3) {
            highscore.drawscreen(window);
            text.showscore(window);
        }

        window.setPosition(Vector2i(0, 0)); // Set window position
        window.display(); // Display window contents
    }
}
