#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include<iostream>
#include"bullet.h"
#include <SFML/Window/Mouse.hpp>
#include"plant.h"

class repeater : public plant // Define a class named repeater derived from plant class
{
    Clock plantClock2; // Clock for repeater actions

public:
    repeater(string address, int x, int y); // Constructor for repeater class
    int collectSun(int x, int y, RenderWindow& window); // Method to collect sun points
    void plantFunctionality(const Event& event, RenderWindow& w); // Method for repeater's functionality
    void drawPlant(RenderWindow& window); // Method to draw repeater on a render window
};


