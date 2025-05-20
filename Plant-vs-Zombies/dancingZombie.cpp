#include "dancingZombie.h"

// Constructor to initialize dancingZombie with parent Zombie properties and additional dancer properties
dancingZombie::dancingZombie(int x, int y) : Zombie(x, y)
{
    // Load dancer textures and set initial properties
    ZombieTexture1.loadFromFile("Images/dancer1.png");
    ZombieTexture2.loadFromFile("Images/dancer2.png");
    ZombieTexture3.loadFromFile("Images/dancer3.png");
    ZombieSprite.setTexture(ZombieTexture1);
    ZombieSprite.setTextureRect(IntRect(0, 0, 52, 92));
    ZombieSprite.setPosition(x, y);
    spawned = false;
    speed = 3;
    // Create spawned normal zombies behind dancing zombie
    for (int i = 0; i < 4; i++) {
        spawnedZombie[i] = new normalZombie(x - (i * 40), y);
    }
}

// Method to handle dancingZombie functionality within the game loop
int dancingZombie::ZombieFunctionality(RenderWindow& w)
{
    int lifeDec = 0;
    if (exists) {
        if (!pause) {
            // Check if the zombie reaches the end of the row
            lifeDec = zombieReached();
            // Move and animate the zombie
            movement();
            animate();
            ZombieSprite.setPosition(row, column);
        }
        w.draw(ZombieSprite); // Draw the zombie on the window
    }
    if (pause) {
        // If paused, pause spawned zombies as well
        for (int i = 0; i < 4; i++) {
            spawnedZombie[i]->changePause();
        }
    }
    if (!spawned) {
        // Set initial positions for spawned zombies
        for (int i = 0; i < 4; i++) {
            spawnedZombie[i]->getSprite().setPosition(row - (i * 40), column);
        }
    }
    if (spawned) {
        // Handle functionality of spawned normal zombies
        for (int i = 0; i < 4; i++) {
            spawnedZombie[i]->ZombieFunctionality(w);
        }
    }
    return lifeDec; // Return any life decrease due to zombie reaching the end
}

// Method to animate the dancing zombie
void dancingZombie::animate()
{
    if (ZombieClock.getElapsedTime().asSeconds() < 1) {
        ZombieSprite.setTexture(ZombieTexture1);
    }
    else if (ZombieClock.getElapsedTime().asSeconds() < 2) {
        spawned = true; // Activate spawned zombies
        ZombieSprite.setTexture(ZombieTexture2);
    }
    else if (ZombieClock.getElapsedTime().asSeconds() < 3) {
        ZombieSprite.setTexture(ZombieTexture3);
    }
    else if (ZombieClock.getElapsedTime().asSeconds() < 4) {
        ZombieSprite.setTexture(ZombieTexture2);
    }
    else {
        ZombieClock.restart(); // Restart animation timer
    }
}

// Method to handle movement of the dancing zombie
void dancingZombie::movement()
{
    // Check if the zombie should change direction
    if (column > 220 + 98 * 4) {
        direction = true;
    }
    if (column < 220) {
        direction = false;
    }
    // Move the zombie diagonally based on direction
    if (moveClock.getElapsedTime().asMilliseconds() / 4) {
        if (direction) {
            row -= speed;
            column -= speed * 2;
        }
        else {
            row -= speed;
            column += speed * 2;
        }
    }
}
