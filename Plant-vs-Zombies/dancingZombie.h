#pragma once // Header guard to prevent multiple inclusions of this header file

#include<iostream> // Include input/output stream library for basic I/O operations
#include <SFML/Graphics.hpp> // Include SFML graphics library
#include <ctime> // Include time library
#include"bullet.h" // Include bullet header file
#include"Zombie.h" // Include Zombie header file
#include"normalZombie.h" // Include normalZombie header file

using namespace sf; // Using SFML namespace
using namespace std; // Using standard namespace

class dancingZombie : public Zombie // Define a class named dancingZombie derived from Zombie class
{
    bool direction; // Flag to track direction
    bool spawned; // Flag to track if spawned
    Zombie* spawnedZombie[4]; // Array to hold spawned zombies

public:
    dancingZombie(int x, int y); // Constructor for dancingZombie class
    int ZombieFunctionality(RenderWindow& w); // Method for zombie's functionality
    void animate(); // Method to animate the zombie
    void movement(); // Method for zombie movement
    void oper(bullet& other); // Method to perform operation with bullet
};
