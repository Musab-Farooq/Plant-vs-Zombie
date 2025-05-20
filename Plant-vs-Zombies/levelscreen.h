#pragma once
#include "screens.h"

class levelscreen : public screens // Define a class named levelscreen derived from screens class
{
public:
    levelscreen(); // Default constructor for levelscreen class
    levelscreen(string p, int num); // Parameterized constructor for levelscreen class
    bool setbutton(sf::RenderWindow& window, sf::Event event, bool check, sf::Mouse mouse); // Method to set button functionality
    bool setlevel1(sf::RenderWindow& window, sf::Event event, bool check, sf::Mouse mouse); // Method to set level 1 functionality
    bool setlevel2(sf::RenderWindow& window, sf::Event event, bool check, sf::Mouse mouse); // Method to set level 2 functionality
    bool setlevel3(sf::RenderWindow& window, sf::Event event, bool check, sf::Mouse mouse); // Method to set level 3 functionality
};
