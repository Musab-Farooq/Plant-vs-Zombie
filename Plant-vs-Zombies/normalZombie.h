#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include"bullet.h"
#include"Zombie.h"
using namespace sf;
using namespace std;

class normalZombie : public Zombie // Define a class named normalZombie derived from Zombie class
{
public:
    normalZombie(int x, int y); // Constructor for normalZombie class
    int ZombieFunctionality(RenderWindow& w); // Method for zombie's functionality
    void animate(); // Method to animate the zombie
};
