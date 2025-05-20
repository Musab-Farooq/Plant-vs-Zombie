#pragma once
#include "screens.h"

class score : public screens // Define a class named score derived from screens class
{
public:
    score(); // Default constructor for score class
    score(string p, int num); // Parameterized constructor for score class
    bool setbutton(sf::RenderWindow& window, sf::Event event, bool check, sf::Mouse mouse); // Method to set button functionality
};