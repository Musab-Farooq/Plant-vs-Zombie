#pragma once
#include "buttons.h"

class Textbox : public button // Define a class named Textbox derived from button class
{
    string inputString; // String to store input text
    sf::Font font2; // Font for input text
    sf::Text inputText; // Text object for input text
    button cancel; // Button object for cancel action
    button ok; // Button object for ok action

public:
    Textbox(); // Default constructor for Textbox class
    Textbox(string p, float sizeX, float sizeY, float posX, float posY, float rotate, sf::Color color); // Parameterized constructor for Textbox class
    void settext(int size, sf::Color color, int positionX, int positionY); // Method to set text properties
    void drawtext(sf::RenderWindow& window); // Method to draw input text on a render window
    void writetext(sf::Event event); // Method to write text based on events
    bool textboxsetcacel(sf::Event event, bool check, sf::Mouse mouse, sf::RenderWindow& window); // Method to handle cancel button functionality
    bool textboxsetok(sf::Event event, bool check, sf::Mouse mouse, sf::RenderWindow& window); // Method to handle ok button functionality
    void save(sf::Event event, sf::Mouse mouse, sf::RenderWindow& window); // Method to save input text
    void showscore(sf::RenderWindow& window); // Method to show score on a render window
};
