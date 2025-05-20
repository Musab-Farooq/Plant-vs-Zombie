#include "Zombie.h"

// Constructor for Zombie object with given position
Zombie::Zombie(int x, int y)
{
    // Initialize member variables
    exists = true;
    pause = false;
    row = x;
    column = y;
    life = 4;
    // Set position and restart clock
    ZombieSprite.setPosition(x, y);
    ZombieClock.restart();
    animateTime = 0;
}

// Default constructor for Zombie object
Zombie::Zombie()
{
    // Initialize member variables with default values
    exists = true;
    row = 500;
    column = 500;
    // Restart clock
    ZombieClock.restart();
}

// Getter method for Zombie sprite
Sprite Zombie::getSprite() const
{
    return ZombieSprite;
}

// Setter method to set existence of Zombie
void Zombie::setExists(bool value)
{
    exists = value;
}

// Getter method to get existence of Zombie
bool Zombie::getExists() const
{
    return exists;
}

// Setter method to set row of Zombie
void Zombie::setRow(int r)
{
    row = r;
}

// Setter method to set column of Zombie
void Zombie::setColumn(int c)
{
    column = c;
}

// Method to set position of Zombie
void Zombie::setPosition(int x, int y)
{
    row = x;
    column = y;
    ZombieSprite.setPosition(x, y);
}

// Getter method to get row of Zombie
int Zombie::getRow() const
{
    return row;
}

// Getter method to get column of Zombie
int Zombie::getColumn() const
{
    return column;
}

// Method to check if Zombie has reached the end
int Zombie::zombieReached()
{
    if (row < 420) {
        exists = false; // Set existence to false if reached end
        return 1; // Return 1 indicating Zombie reached end
    }
    return 0; // Return 0 indicating Zombie hasn't reached end
}

// Method to toggle pause state of Zombie
void Zombie::changePause()
{
    pause = !pause; // Toggle pause state
}

// Method to freeze Zombie movement for a certain time
void Zombie::freeze(float time)
{
    if (ZombieClock.getElapsedTime().asSeconds() - time > 5 && pause) {
        pause = false; // Unfreeze Zombie movement after 5 seconds
    }
}

// Method to handle Zombie collision with bullets
int Zombie::oper(bullet& other)
{
    int score = 0; // Initialize score to 0
    if (other.getType() == 2) {
        // Check if explosive bullet hits Zombie
        if (abs(row - other.getRow()) < 160 && abs(column - other.getColumn()) < 160 && other.getExists() && exists) {
            other.setExists(false); // Set bullet existence to false
            score += 10 * life; // Increase score
            life = 0; // Set Zombie life to 0
        }
    }
    // Check if normal bullet hits Zombie
    if (abs(row - other.getRow()) < 5 && (column - other.getColumn()) < 64 && other.getExists() && exists) {
        other.setExists(false); // Set bullet existence to false
        if (other.getType()) {
            // Freeze Zombie if frozen bullet hits
            float Timefreezed = ZombieClock.getElapsedTime().asSeconds();
            pause = true; // Pause Zombie movement
            freeze(Timefreezed); // Freeze for a certain time
        }
        else if (!other.getType()) {
            score += 10 * life; // Increase score based on Zombie life
            life--; // Decrease Zombie life
        }
    }
    if (life == 0)
        exists = false; // Set existence to false if Zombie's life is 0

    return score; // Return score
}

// Method to handle Zombie collision with plants
void Zombie::collideWithPlant(plant& other)
{
    if (abs(row - other.getRow()) < 5 && abs(column - other.getColumn()) < 5 && exists) {
        if (other.getExists()) {
            pause = true; // Pause Zombie movement if collides with existing plant
            other.setLifeDecrease(true); // Set plant's life decrease flag
        }
        else {
            pause = false; // Resume Zombie movement if no collision with plant
            other.setLifeDecrease(false); // Unset plant's life decrease flag
        }
    }
}
