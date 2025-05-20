#include "levels.h"

// Constructor for the Levels class
levels::levels()
{
    // Load the font and set up text properties
    font.loadFromFile("Fonts/arial.ttf");
    sunText.setFont(font);
    sunText.setCharacterSize(20);
    sunText.setFillColor(sf::Color::Black);

    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::Black);

    playerLifeText.setFont(font);
    playerLifeText.setCharacterSize(20);
    playerLifeText.setFillColor(sf::Color::Black);

    // Create a sunflower object and set initial coordinates for sun collection
    plant* sun = new sunflower("Images/sunflower.png", 50, 670);
    coordinats sunClick{ 0,0 };
    this->suncoordinates = sunClick;
    this->sun = sun;
}

// Function to handle game loop logic
void levels::gameloop(sf::Event event, sf::RenderWindow& window)
{
    // Toggle game pause with 'P' key
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
        resumeGame = !resumeGame;
        // Pause or resume all plants and zombies
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 9; j++) {
                if (p1.getPlant(i, j) != NULL) {
                    (*p1.getPlant(i, j)).changePause();
                }
            }
        }
        for (int i = 0; i < z1.getTotalZombie(); i++) {
            (*z1.getZombie(i)).changePause();
        }
    }

    // Handle mouse click for sun collection if game is not paused
    if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left && resumeGame) {
        suncoordinates.x = event.mouseButton.x;
        suncoordinates.y = event.mouseButton.y;
    }

    // If game is not paused, handle plant deployment
    if (resumeGame) {
        p1.deploy(event, window);
    }
}

// Function to handle exit button functionality
bool levels::exitbutton(sf::Event event, sf::RenderWindow& window, sf::Mouse mouse, bool check)
{
    int posx = sf::Mouse::getPosition(window).x;
    int posy = sf::Mouse::getPosition(window).y;

    if (posx >= 923 && posx <= 1120 && posy >= 40 && posy <= 93)
    {
        exit.setbutton("Images/backbuttoninstruction.png", 350, 150, 850, 10, 0, sf::Color::White);
        if (event.type == sf::Event::MouseButtonPressed)
        {
            check = false;
        }
    }
    else
    {
        exit.setbutton("Images/backbuttoninstruction.png", 300, 100, 880, 20, 0, sf::Color::White);
    }

    return check;
}

// Function to check if the player has won the game
bool levels::wingame()
{
    return z1.GameEnd();
}

// Function to check if the player has lost the game
bool levels::gameover()
{
    if (playerLife <= 0) {
        return true;
    }
    return false;
}

// Function to draw game elements and handle game logic
void levels::draw(sf::Event event, sf::RenderWindow& window)
{
    // If game is running, update plant and zombie interactions
    if (resumeGame) {
        z1.armyMarch();
    }

    // Draw inventory and update currency if game is running
    p1.drawinventory(window);
    if (resumeGame) {
        p1.incCurrency(sun->collectSun(suncoordinates.x, suncoordinates.y, window));
    }

    // Handle plant interactions with zombies and update currency
    sun->plantFunctionality(event, window);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 15; k++) {
                if (p1.getPlant(i, j) == nullptr) {
                    break;
                }
                for (int l = 0; l < z1.getTotalZombie(); l++) {
                    score1 += (*z1.getZombie(l)).oper((*p1.getPlant(i, j)).getBullet(k));
                }
            }
        }
    }

    // Handle zombie interactions with plants
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            if (p1.getPlant(i, j) == nullptr) {
                continue;
            }
            for (int l = 0; l < z1.getTotalZombie(); l++) {
                (*z1.getZombie(l)).collideWithPlant((*p1.getPlant(i, j)));
            }
        }
    }

    // Update plant functionalities and currency collection
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            if (p1.getPlant(i, j) != NULL) {
                (*p1.getPlant(i, j)).plantFunctionality(event, window);
            }
        }
    }
    if (resumeGame) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 9; j++) {
                if ((p1.getPlant(i, j) != NULL))
                    p1.incCurrency((*p1.getPlant(i, j)).collectSun(suncoordinates.x, suncoordinates.y, window));
            }
        }
    }

    // Update zombie functionalities and calculate player life
    for (int i = 0; i < z1.getTotalZombie(); i++) {
        playerLife -= (*z1.getZombie(i)).ZombieFunctionality(window);
    }

    // Reset sun coordinates and update text positions and content
    suncoordinates.x = 0;
    suncoordinates.y = 0;
    sunText.setPosition(91, 91);
    sunText.setString(std::to_string(p1.getCurrency()));  // Set the score 
    playerLifeText.setPosition(10, 300);
    playerLifeText.setString("lifes remaing \n      " + std::to_string(playerLife));  // Set the score 
    scoreText.setPosition(10, 400);
    scoreText.setString("score \n        " + std::to_string(score1));  // Set the score 

    // Draw the texts and exit button
    window.draw(scoreText);
    window.draw(playerLifeText);
    window.draw(sunText);
    exit.drawbutton(window);
}
