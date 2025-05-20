#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include<iostream>
#include <SFML/Window/Mouse.hpp>
#include"plant.h"
using namespace sf;
using namespace std;

class sunflower : public plant // Define a class named sunflower derived from plant class
{
    Texture sunTexture; // Texture for the sun
    Sprite sunSprite; // Sprite for the sun
    bool sunExist; // Flag to check if sun exists

public:
    sunflower(string address, int x, int y); // Constructor with parameters for sunflower class
    sunflower(); // Default constructor for sunflower class
    void makeSun(Clock& cl); // Method to create sun
    void drawPlant(RenderWindow& window); // Method to draw sunflower on a render window
    void changeTexture(); // Method to change texture of sunflower
    int collectSun(int x, int y, RenderWindow& window); // Method to collect sun points
    void plantFunctionality(const Event& event, RenderWindow& w); // Method for sunflower's functionality
};
