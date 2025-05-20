#pragma once
#include "levels.h"

class level3 : public levels // Define a class named level3 derived from levels class
{
public:
    level3(); // Default constructor for level3 class
    virtual void setzombiefactory() override; // Virtual method to set zombie factory (overrides base class method)
    virtual void drawbackground(sf::RenderWindow& window) override; // Virtual method to draw background (overrides base class method)
};