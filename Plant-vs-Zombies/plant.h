#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include<iostream>
#include"bullet.h"
using namespace sf;
using namespace std;

class plant // Define a class named plant
{
protected:
    Texture plantTexture; // Texture for the plant
    Sprite plantSprite; // Sprite for the plant
    Clock plantClock; // Clock for plant actions
    Clock lifeClock; // Clock for plant's life
    bullet* peaBullet; // Pointer to bullet object
    bool pause; // Flag for pausing
    int row; // Row position of the plant
    int column; // Column position of the plant
    int life; // Life of the plant
    bool exists; // Flag to check if the plant exists
    bool lifeDecrease; // Flag to control life decrease
    bool collectable; // Flag to check if the plant is collectable

public:
    plant(string address, int x, int y); // Constructor with parameters for plant class
    plant(); // Default constructor for plant class
    virtual void drawPlant(RenderWindow& window) = 0; // Pure virtual method to draw the plant (to be implemented by derived classes)
    Sprite getSprite() const; // Method to get the plant's sprite
    Texture getTexture() const; // Method to get the plant's texture
    void changePause(); // Method to change the pause state
    void setExists(bool value); // Method to set the existence of the plant
    bool getExists() const; // Method to get the existence state of the plant
    void setRow(int r); // Method to set the row position of the plant
    void setColumn(int c); // Method to set the column position of the plant
    void setSprite(string address); // Method to set the sprite of the plant
    void setPosition(int x, int y); // Method to set the position of the plant
    void setLifeDecrease(bool value); // Method to set the life decrease flag
    int getRow() const; // Method to get the row position of the plant
    int getColumn() const; // Method to get the column position of the plant
    bool getCollectable(); // Method to check if the plant is collectable
    bullet& getBullet(int i); // Method to get a specific bullet of the plant
    void decreaseLife(); // Method to decrease the life of the plant
    virtual int collectSun(int x, int y, RenderWindow& window) = 0; // Pure virtual method to collect sun points (to be implemented by derived classes)
    virtual void plantFunctionality(const Event& event, RenderWindow& w) = 0; // Pure virtual method for plant's functionality (to be implemented by derived classes)
    void operator=(const plant& other); // Assignment operator for plant class
};

