#include "buttons.h" // Include the header file for button class

button::button()
{
	// Initialize button properties to default values
	this->pathbutton = "";
	this->buttonposX = 0;
	this->buttonposY = 0;
	this->buttonsizeX = 0;
	this->buttonsizeY = 0;
	this->buttonrotate = 0;
}

button::button(string p, float sizeX, float sizeY, float posX, float posY, float rotate, sf::Color color)
{
	// Constructor to set button properties based on parameters
	this->pathbutton = p;
	this->buttonposX = posX;
	this->buttonposY = posY;
	this->buttonsizeX = sizeX;
	this->buttonsizeY = sizeY;
	this->buttonrotate = rotate;
	this->color = color;
}

void button::setbutton(string p, float sizeX, float sizeY, float posX, float posY, float rotate, sf::Color color)
{
	// Set button properties based on parameters
	this->pathbutton = p;
	this->buttonposX = posX;
	this->buttonposY = posY;
	this->buttonsizeX = sizeX;
	this->buttonsizeY = sizeY;
	this->buttonrotate = rotate;
	this->color = color;
}

void button::drawbutton(sf::RenderWindow& window)
{
	// Draw the button on the window
	sf::RectangleShape button;
	sf::Texture buttontexture;
	buttontexture.loadFromFile(pathbutton);
	button.setSize(sf::Vector2f(buttonsizeX, buttonsizeY));
	button.setPosition(buttonposX, buttonposY);
	button.setTexture(&buttontexture);
	button.setRotation(buttonrotate);
	button.setFillColor(color);
	window.draw(button);
}

float button::getsizeX()
{
	// Get the size of the button in the X direction
	return buttonsizeX;
}

float button::getsizeY()
{
	// Get the size of the button in the Y direction
	return buttonsizeY;
}

float button::getposX()
{
	// Get the X position of the button
	return buttonposX;
}

float button::getposY()
{
	// Get the Y position of the button
	return buttonposY;
}
