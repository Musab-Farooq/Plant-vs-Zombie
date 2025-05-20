#pragma once // Header guard to prevent multiple inclusions of this header file

#include "screens.h" // Include screens header file

class exitscreen : public screens // Define a class named exitscreen derived from screens class
{
public:
    exitscreen(); // Default constructor for exitscreen class
    exitscreen(string p, int num); // Parameterized constructor for exitscreen class
    bool setbutton(sf::RenderWindow& window, sf::Event event, bool check, sf::Mouse mouse); // Method to set button functionality
};
