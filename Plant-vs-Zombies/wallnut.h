#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include<iostream>
#include"bullet.h"
#include <SFML/Window/Mouse.hpp>
#include"plant.h"

class wallnut : public plant // Define a class named wallnut derived from plant class
{
public:
    wallnut(string address, int x, int y); // Constructor for wallnut class
    int collectSun(int x, int y, RenderWindow& window); // Method to collect sun points
    void plantFunctionality(const Event& event, RenderWindow& w); // Method for wallnut's functionality
    void drawPlant(RenderWindow& window); // Method to draw wallnut on a render window
};


