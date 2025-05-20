#include "cherrybomb.h"

// Constructor to initialize cherrybomb with parent plant properties
cherrybomb::cherrybomb(string address, int x, int y) : plant(address, x, y)
{
    // No specific initialization needed in this constructor
}

// Method to collect sun; returns 0 as cherrybomb doesn't collect sun
int cherrybomb::collectSun(int x, int y, RenderWindow& window)
{
    return 0;
}

// Method to handle cherrybomb functionality based on event and window
void cherrybomb::plantFunctionality(const Event& event, RenderWindow& w)
{
    // Check if cherrybomb exists
    if (exists) {
        // Draw the cherrybomb plant
        drawPlant(w);

        // Check if the plant is not paused
        if (!pause) {
            // Decrease plant life over time
            decreaseLife();

            // Change plant texture based on elapsed time
            if (plantClock.getElapsedTime().asSeconds() < 1) {
                plantTexture.loadFromFile("Images/cherry-bomb.png");
            }
            else if (plantClock.getElapsedTime().asSeconds() < 2) {
                plantTexture.loadFromFile("Images/cherry-bomb1.png");
                peaBullet[0].setExists(true); // Activate the bullet
            }
            else if (plantClock.getElapsedTime().asSeconds() < 3) {
                plantTexture.loadFromFile("Images/cherry-bomb2.png");
                peaBullet[0].setRow(row);
                peaBullet[0].setColumn(column);
                peaBullet[0].setType(2); // Set bullet type
            }
            else {
                peaBullet[0].setExists(false); // Deactivate the bullet
                exists = false; // Deactivate the cherrybomb
            }
        }
    }
}

// Method to draw the cherrybomb plant on the window
void cherrybomb::drawPlant(RenderWindow& window)
{
    if (exists)
        window.draw(plantSprite);
}
