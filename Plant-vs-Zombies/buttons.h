#pragma once // Header guard to prevent multiple inclusions of this header file
#include <iostream> // Include input/output stream library for basic I/O operations
#include <SFML/Graphics.hpp> // Include SFML graphics library
#include <ctime> // Include time library
#include <SFML/Graphics/RenderWindow.hpp> // Include SFML render window library
using namespace std; // Using standard namespace

class button { // Define a class named button
protected:
    string pathbutton; // Path to the button texture/image
    float buttonsizeX; // Size of the button in the X direction
    float buttonsizeY; // Size of the button in the Y direction
    float buttonposX; // X position of the button
    float buttonposY; // Y position of the button
    float buttonrotate; // Rotation angle of the button
    sf::Color color; // Color of the button

public:
    button(); // Default constructor for button class
    button(string p, float sizeX, float sizeY, float posX, float posY, float rotate, sf::Color color); // Parameterized constructor for button class
    void setbutton(string p, float sizeX, float sizeY, float posX, float posY, float rotate, sf::Color color); // Method to set button properties
    void drawbutton(sf::RenderWindow& window); // Method to draw the button on a render window
    float getsizeX(); // Method to get the size of the button in the X direction
    float getsizeY(); // Method to get the size of the button in the Y direction
    float getposX(); // Method to get the X position of the button
    float getposY(); // Method to get the Y position of the button
};
