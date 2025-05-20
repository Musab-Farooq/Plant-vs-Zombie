#include "repeater.h"

// Constructor to initialize repeater object with specified address and position
repeater::repeater(string address, int x, int y) :plant(address, x, y)
{
	// Allocate memory for 15 pea bullets
	peaBullet = new bullet[15]();

	// Initialize pea bullets' positions
	for (int i = 0; i < 15; i++) {
		peaBullet[i].setRow(x + 26);
		peaBullet[i].setColumn(y);
	}
}

// Function to collect sun (not implemented for repeater)
int repeater::collectSun(int x, int y, RenderWindow& window)
{
	return 0;
}

// Function to handle repeater's plant functionality
void repeater::plantFunctionality(const Event& event, RenderWindow& w)
{
	// Check if the repeater plant exists
	if (exists) {
		// Draw the repeater plant on the window
		drawPlant(w);

		// Check if the game is not paused
		if (!pause) {
			// Decrease life of the repeater plant
			decreaseLife();

			// Move the pea bullets and reset their positions if they are not existing
			for (int i = 0; i < 15; i++) {
				if (peaBullet[i].getExists())
					peaBullet[i].moveBullet();
				if (!peaBullet[i].getExists()) {
					peaBullet[i].setRow(row + 26);
					peaBullet[i].setColumn(column);
				}
			}

			// Fire pea bullets at regular intervals
			if (plantClock.getElapsedTime().asSeconds() > 2)
			{
				for (int i = 0; i < 7; i++) {
					if (!peaBullet[i].getExists()) {
						peaBullet[i].setExists(true);
						break;
					}
				}
				plantClock.restart();
			}

			// Fire additional pea bullets at slightly delayed intervals
			if (plantClock2.getElapsedTime().asSeconds() > 2.3)
			{
				for (int i = 7; i < 15; i++) {
					if (!peaBullet[i].getExists()) {
						peaBullet[i].setExists(true);
						break;
					}
				}
				plantClock2 = plantClock;
			}

			// Check if pea bullets have reached the end of their range and reset their positions
			for (int i = 0; i < 15; i++) {
				if (peaBullet[i].getRow() > 1300) {
					peaBullet[i].setExists(false);
					peaBullet[i].setRow(row + 26);
					peaBullet[i].setColumn(column);
				}
			}
		}
	}
}

// Function to draw the repeater plant and its bullets on the window
void repeater::drawPlant(RenderWindow& window)
{
	window.draw(plantSprite);
	for (int i = 0; i < 15; i++) {
		if (peaBullet[i].getExists())
			peaBullet[i].drawBullet(window);
	}
}
