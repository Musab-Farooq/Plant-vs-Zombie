#include "fumeShroom.h"

// Constructor: Initializes a fumeShroom object with a given texture address and position
fumeShroom::fumeShroom(string address, int x, int y) : plant(address, x, y)
{
    // Initialize the array of bullets
    peaBullet = new bullet[15]();

    // Set initial properties for each bullet
    for (int i = 0; i < 15; i++) {
        peaBullet[i].setRow(x + 26);
        peaBullet[i].setColumn(y);
        peaBullet[i].setTexture("Images/fume-bullet.png");
    }
}

// Collect Sun method (not implemented)
int fumeShroom::collectSun(int x, int y, RenderWindow& w)
{
    return 0; // Placeholder return value
}

// Plant functionality during the game loop
void fumeShroom::plantFunctionality(const Event& event, RenderWindow& w)
{
    if (exists) {
        // Draw the fumeShroom plant
        drawPlant(w);

        if (!pause) {
            // Decrease the plant's life over time
            decreaseLife();

            // Move bullets if they exist
            for (int i = 0; i < 15; i++) {
                if (peaBullet[i].getExists())
                    peaBullet[i].moveBullet();

                // Reset bullets that have traveled too far
                if (!peaBullet[i].getExists()) {
                    peaBullet[i].setRow(row + 26);
                    peaBullet[i].setColumn(column);
                }
            }

            // Check if it's time to shoot (every 3 seconds) and set bullets to be shot
            if (plantClock.getElapsedTime().asSeconds() > 3) {
                for (int i = 0; i < 15; i++) {
                    if (!peaBullet[i].getExists()) {
                        peaBullet[i].setExists(true);
                        break;
                    }
                }
                plantClock.restart(); // Restart the clock for shooting interval
            }

            // Check for bullets that have traveled too far and reset them
            for (int i = 0; i < 15; i++) {
                if (peaBullet[i].getRow() - this->getRow() > 400) {
                    peaBullet[i].setExists(false);
                    peaBullet[i].setRow(row + 26);
                    peaBullet[i].setColumn(column);
                }
            }
        }
    }
}

// Draw the fumeShroom plant and its bullets on the window
void fumeShroom::drawPlant(RenderWindow& window)
{
    window.draw(plantSprite); // Draw the fumeShroom plant

    // Draw bullets if they exist
    for (int i = 0; i < 15; i++) {
        if (peaBullet[i].getExists())
            peaBullet[i].drawBullet(window);
    }
}
