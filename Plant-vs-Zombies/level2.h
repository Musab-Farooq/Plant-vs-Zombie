#pragma once
#include "levels.h"

class level2 : public levels // Define a class named level2 derived from levels class
{
public:
    level2(); // Default constructor for level2 class
    virtual void setzombiefactory() override; // Virtual method to set zombie factory (overrides base class method)
    virtual void drawbackground(sf::RenderWindow& window) override; // Virtual method to draw background (overrides base class method)
};
