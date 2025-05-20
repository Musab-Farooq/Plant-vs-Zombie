#pragma once
#include "buttons.h"

class screens // Define a class named screens
{
    button* buttons; // Pointer to buttons array
    string pathscreen; // Path for the screen
    int buttonnum; // Number of buttons

public:
    screens(); // Default constructor for screens class
    screens(string p, int num); // Parameterized constructor for screens class
    void setpath(string p); // Method to set the path for the screen
    button& changebutton(int position); // Method to change a button at a specific position
    void drawscreen(sf::RenderWindow& window); // Method to draw the screen on a render window
};
