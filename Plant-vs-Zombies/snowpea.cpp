#include "snowPea.h"

// Constructor for snowPea class
snowPea::snowPea(string address, int x, int y) : plant(address, x, y)
{
    // Initialize peaBullet array
    peaBullet = new bullet[15]();
    for (int i = 0; i < 15; i++) {
        peaBullet[i].setRow(x + 26);
        peaBullet[i].setColumn(y);
        peaBullet[i].setTexture("Images/snow-pea-bullet.png"); // Set bullet texture
        peaBullet[i].setspeed(16); // Set bullet speed
        peaBullet[i].setType(1); // Set bullet type (1 for snow pea bullet)
    }
}

// Function to collect sun points (not implemented)
int snowPea::collectSun(int x, int y, RenderWindow& window)
{
    return 0;
}

// Function to handle plant functionality
void snowPea::plantFunctionality(const Event& event, RenderWindow& w)
{
    if (exists) {
        drawPlant(w); // Draw the snowPea plant
        if (!pause) {
            decreaseLife(); // Decrease plant life over time
            for (int i = 0; i < 15; i++) {
                if (peaBullet[i].getExists())
                    peaBullet[i].moveBullet(); // Move active snow pea bullets
                if (!peaBullet[i].getExists()) {
                    peaBullet[i].setRow(row + 26);
                    peaBullet[i].setColumn(column);
                }
            }

            // Check if it's time to shoot a new snow pea bullet
            if (plantClock.getElapsedTime().asSeconds() > 3)
            {
                for (int i = 0; i < 15; i++) {
                    if (!peaBullet[i].getExists()) {
                        peaBullet[i].setExists(true); // Activate a snow pea bullet
                        break;
                    }
                }
                plantClock.restart(); // Restart the shooting timer
            }

            // Check if any snow pea bullets have reached the end
            for (int i = 0; i < 15; i++) {
                if (peaBullet[i].getRow() > 1300) {
                    peaBullet[i].setExists(false); // Deactivate snow pea bullet
                    peaBullet[i].setRow(row + 26);
                    peaBullet[i].setColumn(column);
                }
            }
        }
    }
}

// Function to draw the snowPea plant and its bullets
void snowPea::drawPlant(RenderWindow& window)
{
    window.draw(plantSprite); // Draw the snowPea plant sprite
    for (int i = 0; i < 15; i++) {
        if (peaBullet[i].getExists())
            peaBullet[i].drawBullet(window); // Draw active snow pea bullets
    }
}
