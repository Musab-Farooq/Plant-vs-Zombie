#pragma once
#include "levels.h"

class level1 : public levels // Define a class named level1 derived from levels class
{
public:
    level1(); // Default constructor for level1 class
    virtual void setzombiefactory() override; // Virtual method to set zombie factory (overrides base class method)
    virtual void drawbackground(sf::RenderWindow& window) override; // Virtual method to draw background (overrides base class method)
};
