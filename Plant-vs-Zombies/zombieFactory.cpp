#include "zombieFactory.h"

// Default constructor for zombieFactory object
zombieFactory::zombieFactory()
{
}

// Constructor for zombieFactory object with level parameter
zombieFactory::zombieFactory(int level)
{
    // Initialize member variables
    for (int i = 0; i < 50; i++) {
        zombieArmy[i] = nullptr;
    }
    levelNumber = level;
    totalZombie = (10 * level);
    wave = 0;
    zombieGo = 0;
    nextWave = true;
}

// Method to create zombie army based on level
void zombieFactory::armyCreation()
{
    switch (levelNumber)
    {
    case 1:
        // Create normal zombies for level 1
        for (int i = 0; i < totalZombie; i++) {
            int y = (rand() % 5) * 98 + 220;
            int x = 1200;
            zombieArmy[i] = new normalZombie(x, y);
            zombieArmy[i]->setExists(false);
        }
        break;

    default:
        // Create different types of zombies for higher levels
        for (int i = 0; i < totalZombie; i++) {
            int y = (rand() % 5) * 98 + 220;
            int x = 1200;
            int random = (rand() % 4);
            switch (random)
            {
            case 0:
                zombieArmy[i] = new normalZombie(x, y);
                break;
            case 1:
                zombieArmy[i] = new dancingZombie(x, y);
                break;
            case 2:
                zombieArmy[i] = new footballZombie(x, y);
                break;
            case 3:
                zombieArmy[i] = new flyingZombie(x, y);
                break;
            default:
                break;
            }
            zombieArmy[i]->setExists(false);
        }
        break;
    }
}

// Method to make zombies march towards the plants
void zombieFactory::armyMarch()
{
    // Deploy zombies with a delay
    if (deployClock.getElapsedTime().asSeconds() > 10 && nextWave && zombieGo < totalZombie) {
        zombieArmy[zombieGo]->setExists(true);
        zombieGo++;
        deployClock.restart();
    }
}

// Method to get a specific zombie from the army
Zombie* zombieFactory::getZombie(int i)
{
    return zombieArmy[i];
}

// Method to get the total number of zombies in the army
int zombieFactory::getTotalZombie()
{
    return totalZombie;
}

// Method to send the next wave of zombies
void zombieFactory::sendNextWave()
{
    bool eliminated = true;
    if (!nextWave) {
        // Check if current wave is eliminated
        for (int i = 0; i < totalZombie; i++) {
            if (zombieArmy[i]->getExists()) {
                eliminated = false;
            }
        }
    }
    // If current wave is eliminated, set next wave flag to true
    if (eliminated)
        nextWave = true;
}

// Method to check if the game has ended
bool zombieFactory::GameEnd()
{
    // If not all zombies are deployed, game is not ended
    if (zombieGo != totalZombie) {
        return false;
    }
    bool eliminated = true;
    // Check if all zombies are eliminated
    if (zombieGo == totalZombie) {
        for (int i = 0; i < totalZombie; i++) {
            if (zombieArmy[i]->getExists()) {
                eliminated = false;
            }
        }
    }
    return eliminated;
}
