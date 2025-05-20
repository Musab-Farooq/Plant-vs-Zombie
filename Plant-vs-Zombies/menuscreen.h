#pragma once
#include "screens.h"

class mainmenu : public screens // Define a class named mainmenu derived from screens class
{
public:
    mainmenu(); // Default constructor for mainmenu class
    mainmenu(string p, int num); // Parameterized constructor for mainmenu class
    bool setlevel(sf::RenderWindow& window, sf::Event event, bool check, sf::Mouse mouse); // Method to set level functionality
    bool setinstructions(sf::RenderWindow& window, sf::Event event, bool check, sf::Mouse mouse); // Method to set instructions functionality
    bool sethighscore(sf::RenderWindow& window, sf::Event event, bool check, sf::Mouse mouse); // Method to set high score functionality
};
