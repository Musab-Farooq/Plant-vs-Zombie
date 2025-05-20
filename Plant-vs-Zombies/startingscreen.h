#pragma once
#include "screens.h"

class startingscreen : public screens // Define a class named startingscreen derived from screens class
{
public:
    startingscreen(); // Default constructor for startingscreen class
    startingscreen(string p, int num); // Parameterized constructor for startingscreen class
    bool setbutton(sf::RenderWindow& window, sf::Event event, bool check, sf::Mouse mouse); // Method to set button functionality
};
