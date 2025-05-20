#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <ctime>
#include<iostream>
#include"plant.h"
#include"peaPlant.h"
#include"sunflower.h"
#include"wallnut.h"
#include"snowPea.h"
#include"cherrybomb.h"
#include"repeater.h"
#include"fumeShroom.h"

using namespace sf;
using namespace std;

class plantFactory // Define a class named plantFactory
{
    Texture inventoryTexture[7]; // Array of textures for inventory items
    Sprite inventorySprite[7]; // Array of sprites for inventory items
    string plantAddress[7]; // Array of addresses for plants
    int inventoryPrice[7]; // Array of prices for inventory items
    int inventoryTabHeight; // Height of the inventory tab
    int inventoryTabWidth; // Width of the inventory tab
    plant* plants[5][9]; // 2D array to store plants in a grid
    int current_x; // Current x position
    int current_y; // Current y position
    int currency; // Currency amount
    bool drag; // Flag for dragging
    int numberOfPlants; // Number of plants
    bool available; // Flag for availability
    int selectedPlant; // Selected plant index
    plant* current_plant; // Pointer to the current plant

public:
    plantFactory(); // Default constructor for plantFactory class
    void drawinventory(RenderWindow& window); // Method to draw inventory items on the window
    bool checkAvaibilty(int selectedPlant); // Method to check availability of a selected plant
    plant* getPlant(int i, int j); // Method to get a plant from the grid
    Sprite getSprites(int i); // Method to get the sprite of an inventory item
    void deploy(const Event& deploy_event, RenderWindow& window); // Method to deploy a plant
    bool vaild(); // Method to validate
    void addPlants(); // Method to add plants
    int getNumberOfPlants(); // Method to get the number of plants
    bool placementValidation(int row, int column); // Method to validate placement of a plant
    void removePlant(); // Method to remove a plant
    void incCurrency(int i); // Method to increase currency
    int getCurrency(); // Method to get currency amount
};


