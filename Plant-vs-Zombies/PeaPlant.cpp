#include "peaPlant.h"

peaPlant::peaPlant(string address, int x, int y) : plant(address, x, y)
{
	// Initialize the pea bullets array for the plant
	peaBullet = new bullet[15]();
	for (int i = 0; i < 15; i++) {
		peaBullet[i].setRow(x + 26);
		peaBullet[i].setColumn(y);
	}
}

void peaPlant::plantFunctionality(const Event& event, RenderWindow& w)
{
	// Check if the plant exists
	if (exists) {
		// Draw the plant on the window
		drawPlant(w);

		// Check if the game is not paused
		if (!pause) {
			// Decrease plant's life over time
			decreaseLife();

			// Move and manage pea bullets
			for (int i = 0; i < 15; i++) {
				if (peaBullet[i].getExists())
					peaBullet[i].moveBullet();
				if (!peaBullet[i].getExists()) {
					// Reset position of inactive bullets
					peaBullet[i].setRow(row + 26);
					peaBullet[i].setColumn(column);
				}
			}

			// Manage shooting cooldown and bullet creation
			if (plantClock.getElapsedTime().asSeconds() > 3)
			{
				for (int i = 0; i < 15; i++) {
					if (!peaBullet[i].getExists()) {
						// Activate a bullet if available
						peaBullet[i].setExists(true);
						break;
					}
				}
				// Restart the shooting cooldown timer
				plantClock.restart();
			}

			// Reset bullets that go off-screen
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

int peaPlant::collectSun(int x, int y, RenderWindow& window)
{
	return 0; // Placeholder for sun collection mechanism
}

void peaPlant::drawPlant(RenderWindow& window)
{
	// Draw the plant sprite on the window
	window.draw(plantSprite);

	// Draw active pea bullets on the window
	for (int i = 0; i < 15; i++) {
		if (peaBullet[i].getExists())
			peaBullet[i].drawBullet(window);
	}
}
