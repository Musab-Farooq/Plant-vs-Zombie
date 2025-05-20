#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include"bullet.h"
#include"Zombie.h"
using namespace sf;
using namespace std;
class footballZombie :public Zombie // Define a class named footballZombie derived from Zombie class
{
    bool moving; // Flag to track if the zombie is moving

public:
    footballZombie(int x, int y); // Constructor for footballZombie class
    int ZombieFunctionality(RenderWindow& w); // Method for zombie's functionality
    void animate(); // Method to animate the zombie
    void movement(); // Method for zombie movement
    void oper(bullet& other); // Method to perform operation with bullet
};
