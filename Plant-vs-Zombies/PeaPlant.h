#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include<iostream>
#include"bullet.h"
#include <SFML/Window/Mouse.hpp>
#include"plant.h"

class peaPlant : public plant // Define a class named peaPlant derived from plant class
{
public:
    peaPlant(string address, int x, int y); // Constructor for peaPlant class
    void plantFunctionality(const Event& event, RenderWindow& w); // Method for peaPlant's functionality
    virtual int collectSun(int x, int y, RenderWindow& w); // Virtual method to collect sun points (may be overridden by derived classes)
    void drawPlant(RenderWindow& window); // Method to draw peaPlant on a render window
};

