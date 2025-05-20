#pragma once
#include "screens.h"

class instructionscreen : public screens // Define a class named instructionscreen derived from screens class
{
public:
    instructionscreen(); // Default constructor for instructionscreen class
    instructionscreen(string p, int num); // Parameterized constructor for instructionscreen class
    void setinstructions(sf::RenderWindow& window); 
    bool setbutton(sf::RenderWindow& window, sf::Event event, bool check, sf::Mouse mouse); // Method to set button functionality
};
