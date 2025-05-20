#include "bullet.h"

bullet::bullet()
{
	// Initialize bullet properties
	exists = false; // Bullet does not exist initially
	bulletTexture.loadFromFile("Images/pea-shooter-bullet.png"); // Load bullet texture
	bulletSprite.setTexture(bulletTexture); // Set texture to bullet sprite
	bulletSprite.setTextureRect(IntRect(0, 0, 26, 26)); // Set texture rectangle
	bulletClock.restart(); // Restart clock for timing
	speed = 8; // Set default speed
	type = 0; // Set default type
}

void bullet::drawBullet(RenderWindow& window)
{
	// Draw bullet if it exists
	if (exists) {
		bulletSprite.setPosition(row, column); // Set bullet position
		window.draw(bulletSprite); // Draw bullet on the window
	}
}

Sprite bullet::getSprite() const
{
	return bulletSprite; // Return bullet sprite
}

void bullet::setTexture(string address)
{
	bulletTexture.loadFromFile(address); // Load texture from file
}

void bullet::setExists(bool value)
{
	exists = value; // Set bullet existence
}

bool bullet::getExists() const
{
	return exists; // Get bullet existence status
}

void bullet::setRow(int r)
{
	row = r; // Set bullet row position
}

void bullet::setColumn(int c)
{
	column = c; // Set bullet column position
}

int bullet::getRow() const
{
	return row; // Get bullet row position
}

int bullet::getColumn() const
{
	return column; // Get bullet column position
}

void bullet::moveBullet()
{
	// Move bullet if it exists and update position
	if (bulletClock.getElapsedTime().asMilliseconds() / 4 && exists) {
		row += speed; // Move bullet horizontally
		bulletClock.restart(); // Restart clock for timing
	}
}

void bullet::setspeed(int speedToBeSet)
{
	speed = speedToBeSet; // Set bullet speed
}

void bullet::setType(int typeNo)
{
	type = typeNo; // Set bullet type
}

int bullet::getType()
{
	return type; // Get bullet type
}
