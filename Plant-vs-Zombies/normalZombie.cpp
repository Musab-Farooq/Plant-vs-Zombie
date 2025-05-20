#include "normalZombie.h"

normalZombie::normalZombie(int x, int y) : Zombie(x, y)
{
	// Load zombie textures from files
	ZombieTexture1.loadFromFile("Images/simple1.png");
	ZombieTexture2.loadFromFile("Images/simple3.png");
	ZombieTexture3.loadFromFile("Images/simple5.png");

	// Set initial zombie properties
	ZombieSprite.setTexture(ZombieTexture1);
	life = 2;
	ZombieSprite.setTextureRect(IntRect(0, 0, 42, 62));
	speed = 1;
	ZombieSprite.setPosition(x, y);
}

int normalZombie::ZombieFunctionality(RenderWindow& w)
{
	int lifeDec = 0;
	if (exists) {
		if (!pause) {
			// Check if the zombie reaches the end of the lane
			lifeDec = zombieReached();

			// Animate the zombie
			animate();

			// Update zombie position
			ZombieSprite.setPosition(row, column);
		}
		// Draw the zombie on the window
		w.draw(ZombieSprite);
	}
	return lifeDec;
}

void normalZombie::animate()
{
	// Check the elapsed time for animation
	if (ZombieClock.getElapsedTime().asSeconds() < 1) {
		// First animation phase
		row -= speed;
		ZombieSprite.setTexture(ZombieTexture1);
	}
	else if (ZombieClock.getElapsedTime().asSeconds() < 2) {
		// Second animation phase
		row -= speed;
		ZombieSprite.setTexture(ZombieTexture2);
	}
	else if (ZombieClock.getElapsedTime().asSeconds() < 3) {
		// Third animation phase
		row -= speed;
		ZombieSprite.setTexture(ZombieTexture3);
	}
	else if (ZombieClock.getElapsedTime().asSeconds() < 4) {
		// Fourth animation phase
		row -= speed;
		ZombieSprite.setTexture(ZombieTexture2);
	}
	else {
		// Restart the animation cycle
		ZombieClock.restart();
	}
}
