#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include"bullet.h"
#include"plant.h"
using namespace sf;
using namespace std;

class Zombie // Define a class named Zombie
{
protected:
    Texture ZombieTexture1; // Texture for Zombie in state 1
    Texture ZombieTexture2; // Texture for Zombie in state 2
    Texture ZombieTexture3; // Texture for Zombie in state 3
    Sprite ZombieSprite; // Sprite for Zombie
    Clock ZombieClock; // Clock for Zombie actions
    Clock moveClock; // Clock for Zombie movement
    bool pause; // Flag for pausing
    float animateTime; // Animation time
    int life; // Life of the Zombie
    int row; // Row position of the Zombie
    int column; // Column position of the Zombie
    bool exists; // Flag to check if the Zombie exists
    int speed; // Speed of the Zombie

public:
    Zombie(int x, int y); // Constructor for Zombie class with parameters
    Zombie(); // Default constructor for Zombie class
    Sprite getSprite() const; // Method to get the Zombie's sprite
    void setExists(bool value); // Method to set the existence of the Zombie
    bool getExists() const; // Method to get the existence state of the Zombie
    void setRow(int r); // Method to set the row position of the Zombie
    void setColumn(int c); // Method to set the column position of the Zombie
    void setPosition(int x, int y); // Method to set the position of the Zombie
    int getRow() const; // Method to get the row position of the Zombie
    int getColumn() const; // Method to get the column position of the Zombie
    int zombieReached(); // Method to check if the Zombie has reached a target
    void changePause(); // Method to change the pause state
    void freeze(float); // Method to freeze the Zombie for a duration
    virtual int ZombieFunctionality(RenderWindow& w) = 0; // Pure virtual method for Zombie's functionality (to be implemented by derived classes)
    int oper(bullet& other); // Method to operate on a bullet
    virtual void collideWithPlant(plant& other); // Virtual method to handle collision with a plant (may be overridden by derived classes)
};

