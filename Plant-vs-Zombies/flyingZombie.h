#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include"bullet.h"
#include"Zombie.h"
using namespace sf;
using namespace std;
class flyingZombie :public Zombie // Define a class named flyingZombie derived from Zombie class
{
public:
    flyingZombie(int x, int y); // Constructor for flyingZombie class
    int ZombieFunctionality(RenderWindow& w); // Method for zombie's functionality
    void animate(); // Method to animate the zombie
    void movement(); // Method for zombie movement
    void oper(bullet& other); // Method to perform operation with bullet
    void collideWithPlant(plant& other) override; // Method to handle collision with plant (overridden from base class)
};
