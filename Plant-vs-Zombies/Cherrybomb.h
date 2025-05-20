#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include<iostream>
#include"bullet.h" // Include bullet header file
#include <SFML/Window/Mouse.hpp>
#include"plant.h" // Include plant header file
#include"zombieFactory.h" // Include zombieFactory header file
#include"Zombie.h" // Include Zombie header file

class cherrybomb : public plant
{
    bullet bomb; // Instance of bullet class for cherrybomb

public:
    cherrybomb(string address, int x, int y); // Constructor for cherrybomb class
    int collectSun(int x, int y, RenderWindow& w); // Method to collect sun points
    void plantFunctionality(const Event& event, RenderWindow& window); // Method for cherrybomb's functionality
    void drawPlant(RenderWindow& window); // Method to draw cherrybomb on a render window
};
