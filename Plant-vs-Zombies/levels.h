#pragma once
#include "plantFactory.h"
#include "zombieFactory.h"
#include "buttons.h"

struct coordinats {
	int x;
	int y;
};

class levels{ // Define a class named levels
protected:
    plantFactory p1; // Instance of plantFactory for creating plants
    zombieFactory z1; // Instance of zombieFactory for creating zombies
    coordinats suncoordinates; // Coordinates for sun
    plant* sun; // Pointer to a plant object for sun
    sf::Text sunText; // Text object for displaying sun count
    sf::Text playerLifeText; // Text object for displaying player life
    sf::Text scoreText; // Text object for displaying score
    sf::Font font; // Font for text objects
    int score1 = 0; // Score variable
    int playerLife = 3; // Player life variable
    bool resumeGame = true; // Flag to resume game
    button exit; // Button object for exiting game

public:
    levels(); // Default constructor for levels class
    virtual void setzombiefactory() = 0; // Pure virtual method to set zombie factory (to be implemented by derived classes)
    void gameloop(sf::Event event, sf::RenderWindow& window); // Method to run the game loop
    virtual void drawbackground(sf::RenderWindow& window) = 0; // Pure virtual method to draw background (to be implemented by derived classes)
    bool exitbutton(sf::Event event, sf::RenderWindow& window, sf::Mouse mouse, bool check); // Method to handle exit button functionality
    bool wingame(); // Method to check if player wins the game
    bool gameover(); // Method to check if game is over
    void draw(sf::Event event, sf::RenderWindow& window); // Method to draw game elements
};
