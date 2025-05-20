#include "flyingZombie.h"

// Constructor for flyingZombie
flyingZombie::flyingZombie(int x, int y) : Zombie(x, y)
{
	// Load textures and set initial properties
	ZombieTexture1.loadFromFile("Images/balloon.png");
	ZombieTexture2.loadFromFile("Images/balloon.png");
	ZombieTexture3.loadFromFile("Images/balloon.png");
	ZombieSprite.setTexture(ZombieTexture1);
	ZombieSprite.setTextureRect(sf::IntRect(0, 0, 42, 64)); // Set texture rectangle
	ZombieSprite.setPosition(x, y - 50); // Adjust position for flying effect
	speed = 2; // Set initial speed
}

// Function to handle zombie functionality
int flyingZombie::ZombieFunctionality(RenderWindow& w)
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

// Function to animate the zombie
void flyingZombie::animate()
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
	else {
		ZombieClock.restart(); // Restart clock for continuous animation
	}
}

// Function to handle zombie movement
void flyingZombie::movement()
{
	if (moveClock.getElapsedTime().asMilliseconds() / 10) {
		row -= speed; // Move the zombie vertically
	}
}

// Function to handle zombie interaction with bullets
void flyingZombie::oper(bullet& other)
{
	if (row - other.getRow() <= 5 && (column - other.getColumn() >= -5 || column - other.getColumn() <= 5)) {
		other.setExists(false); // Set bullet to not exist
		life--; // Decrease zombie life
	}
	if (life == 0)
		exists = false; // Set zombie to not exist if life reaches zero
}

// Function to handle zombie collision with plants
void flyingZombie::collideWithPlant(plant& other)
{
	// No collision behavior for flying zombies
	return;
}
