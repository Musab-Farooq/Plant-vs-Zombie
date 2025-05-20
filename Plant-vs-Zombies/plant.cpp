#include "plant.h"

// Constructor to create a plant object with specified texture, position, and properties
plant::plant(string address, int x, int y)
{
	// Initialize plant properties
	exists = true;
	plantTexture.loadFromFile(address);
	plantSprite.setTexture(plantTexture);
	plantSprite.setTextureRect(IntRect(0, 0, 42, 42));
	row = x;
	column = y;
	life = 3;
	lifeDecrease = false;
	plantSprite.setPosition(x, y);
	plantClock.restart();
	collectable = false;
	peaBullet = new bullet[15];
	pause = false;
}

// Default constructor for a plant object with default texture and no position
plant::plant()
{
	plantTexture.loadFromFile("Images/sun.png");
	plantSprite.setTexture(plantTexture);
	plantSprite.setTextureRect(IntRect(0, 0, 42, 42));
	int row = 0;
	int column = 0;
	exists = false;
}

// Getter function to return the plant's sprite
Sprite plant::getSprite() const
{
	return plantSprite;
}

// Getter function to return the plant's texture
Texture plant::getTexture() const
{
	return plantTexture;
}

// Function to toggle the pause state of the plant
void plant::changePause()
{
	pause = !pause;
}

// Setter function to set the existence status of the plant
void plant::setExists(bool value)
{
	exists = value;
}

// Getter function to get the existence status of the plant
bool plant::getExists() const
{
	return exists;
}

// Setter function to set the row position of the plant
void plant::setRow(int r)
{
	row = r;
}

// Setter function to set the column position of the plant
void plant::setColumn(int c)
{
	column = c;
}

// Setter function to set the sprite of the plant
void plant::setSprite(string address)
{
	plantTexture.loadFromFile(address);
	plantSprite.setTexture(plantTexture);
	plantSprite.setTextureRect(IntRect(0, 0, 64, 64));
}

// Setter function to set the position of the plant
void plant::setPosition(int x, int y)
{
	row = x;
	column = y;
	plantSprite.setPosition(x, y);
}

// Setter function to set the life decrease status of the plant
void plant::setLifeDecrease(bool value)
{
	lifeDecrease = value;
}

// Getter function to get the row position of the plant
int plant::getRow() const
{
	return row;
}

// Getter function to get the column position of the plant
int plant::getColumn() const
{
	return column;
}

// Getter function to check if the plant is collectable
bool plant::getCollectable()
{
	return collectable;
}

// Getter function to access a specific bullet of the plant
bullet& plant::getBullet(int i)
{
	if (peaBullet != nullptr)
		return peaBullet[i];
}

// Function to decrease the life of the plant over time
void plant::decreaseLife()
{
	if (lifeDecrease) {

		if (lifeClock.getElapsedTime().asSeconds() > 1) {
			life--;
			lifeClock.restart();
		}
		if (life == 0)
			exists = false;
	}
}

// Overloaded assignment operator to copy the properties of another plant object
void plant::operator=(const plant& other)
{
	plantTexture = other.getTexture();
	plantSprite.setTexture(plantTexture);
	plantSprite.setTextureRect(IntRect(0, 0, 64, 64));
	row = other.getRow();
	column = other.getColumn();
	plantSprite.setPosition(row, column);
}
