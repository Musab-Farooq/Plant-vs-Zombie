#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include<iostream>
#include"bullet.h"
#include <SFML/Window/Mouse.hpp>
#include"plant.h"

class fumeShroom : public plant // Define a class named fumeShroom derived from plant class
{
public:
    fumeShroom(string address, int x, int y); // Constructor for fumeShroom class
    int collectSun(int x, int y, RenderWindow& w); // Method to collect sun points
    void plantFunctionality(const Event& event, RenderWindow& w); // Method for fumeShroom's functionality
    void drawPlant(RenderWindow& window); // Method to draw fumeShroom on a render window
};


