#pragma once
#pragma once
#include <SFML/Graphics.hpp> // Include SFML graphics library
#include <ctime> // Include time library
#include<iostream> // Include input/output stream library for basic I/O operations
using namespace sf; // Using SFML namespace
using namespace std; // Using standard namespace

class bullet // Define a class named bullet
{
private:
    Texture bulletTexture; // Texture object for bullet
    Sprite bulletSprite; // Sprite object for bullet
    Clock bulletClock; // Clock object for bullet timing
    int speed; // Speed of the bullet
    int row; // Row position of the bullet
    int column; // Column position of the bullet
    int type; // Type of the bullet
    bool exists; // Flag indicating if the bullet exists or not

public:
    bullet(); // Constructor for bullet class
    void drawBullet(RenderWindow& window); // Method to draw the bullet on a window
    Sprite getSprite() const; // Method to get the sprite of the bullet
    void setTexture(string address); // Method to set the texture of the bullet
    void setExists(bool value); // Method to set the existence of the bullet
    bool getExists() const; // Method to get the existence status of the bullet
    void setRow(int r); // Method to set the row position of the bullet
    void setColumn(int c); // Method to set the column position of the bullet
    int getRow() const; // Method to get the row position of the bullet
    int getColumn() const; // Method to get the column position of the bullet
    void moveBullet(); // Method to move the bullet
    void setspeed(int speed); // Method to set the speed of the bullet
    void setType(int typeNo); // Method to set the type of the bullet
    int getType(); // Method to get the type of the bullet
};
