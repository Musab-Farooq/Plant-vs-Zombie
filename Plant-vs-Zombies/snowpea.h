#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include<iostream>
#include"bullet.h"
#include <SFML/Window/Mouse.hpp>
#include"plant.h"

class snowPea : public plant // Define a class named snowPea derived from plant class
{
public:
    snowPea(string address, int x, int y); // Constructor for snowPea class
    int collectSun(int x, int y, RenderWindow& window); // Method to collect sun points
    void plantFunctionality(const Event& event, RenderWindow& w); // Method for snowPea's functionality
    void drawPlant(RenderWindow& window); // Method to draw snowPea on a render window
};


