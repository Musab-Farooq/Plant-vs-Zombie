#include "footballZombie.h"

footballZombie::footballZombie(int x, int y) : Zombie(x, y)
{
	// Load textures and set initial properties
	ZombieTexture1.loadFromFile("Images/footbll1.png");
	ZombieTexture2.loadFromFile("Images/footbll3.png");
	ZombieTexture3.loadFromFile("Images/footbll2.png");
	ZombieSprite.setTexture(ZombieTexture1);
	ZombieSprite.setTextureRect(sf::IntRect(0, 0, 108, 96)); // Set texture rectangle
	ZombieSprite.setPosition(x, y);
	moving = true;
	speed = 2;
	life = 4; // Set initial life value
}

int footballZombie::ZombieFunctionality(RenderWindow& w)
{
	int lifeDec = 0;
	if (exists) {
		if (!pause) {
			lifeDec = zombieReached(); // Check if zombie reached the end
			movement(); // Move the zombie
			animate(); // Animate the zombie
			ZombieSprite.setPosition(row, column); // Set the position of the sprite
		}
		w.draw(ZombieSprite); // Draw the zombie sprite
	}
	return lifeDec; // Return life decrease value
}

void footballZombie::animate()
{
	if (ZombieClock.getElapsedTime().asSeconds() < 1) {
		ZombieSprite.setTexture(ZombieTexture1); // Set texture for first phase of animation
	}
	else if (ZombieClock.getElapsedTime().asSeconds() < 2) {
		ZombieSprite.setTexture(ZombieTexture2); // Set texture for second phase of animation
	}
	else if (ZombieClock.getElapsedTime().asSeconds() < 3) {
		ZombieSprite.setTexture(ZombieTexture3); // Set texture for third phase of animation
	}
	else if (ZombieClock.getElapsedTime().asSeconds() < 4) {
		ZombieSprite.setTexture(ZombieTexture2); // Set texture for fourth phase of animation
	}
	else
	{
		ZombieClock.restart(); // Restart clock for continuous animation
	}
}

void footballZombie::movement()
{
	if (column == 220) {
		moving = false; // Stop moving horizontally when column reaches 220
	}
	if (moveClock.getElapsedTime().asSeconds() < 5) {
		row -= speed; // Move vertically initially
	}
	else if (moveClock.getElapsedTime().asSeconds() < 5.1) {
		if (moving)
			column -= 40; // Move left after a delay
		else
			column += 40; // Move right after a delay
	}
	else if (moveClock.getElapsedTime().asSeconds() < 10) {
		row -= speed; // Move vertically again
	}
	else if (moveClock.getElapsedTime().asSeconds() < 10.1) {
		if (moving)
			column += 40; // Move right after a delay
		else
			column -= 40; // Move left after a delay
	}
	else {
		moveClock.restart(); // Restart the movement clock
	}
}
