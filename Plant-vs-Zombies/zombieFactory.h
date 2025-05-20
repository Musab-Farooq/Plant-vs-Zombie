#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <cstdlib> 
#include <ctime>
#include<iostream>
#include"Zombie.h"
#include"normalZombie.h"
#include"dancingZombie.h"
#include"footballZombie.h"
#include"flyingZombie.h"

using namespace sf;
using namespace std;

class zombieFactory // Define a class named zombieFactory
{
    Zombie* zombieArmy[50]; // Array of pointers to Zombie objects
    Clock deployClock; // Clock for deploying Zombies
    int levelNumber; // Level number
    int totalZombie; // Total number of Zombies
    int wave; // Current wave number
    int zombieGo; // Number of Zombies marching
    bool nextWave; // Flag to indicate next wave

public:
    zombieFactory(); // Default constructor for zombieFactory class
    zombieFactory(int level); // Constructor with parameter for zombieFactory class
    void armyCreation(); // Method to create the Zombie army
    void armyMarch(); // Method for Zombie army to march
    Zombie* getZombie(int i); // Method to get a Zombie from the army
    int getTotalZombie(); // Method to get the total number of Zombies
    void sendNextWave(); // Method to send the next wave of Zombies
    bool GameEnd(); // Method to check if the game has ended
};


