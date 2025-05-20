#include "plantFactory.h"

// Constructor to initialize the plant factory object
plantFactory::plantFactory()
{
	// Initialize variables
	available = false;
	inventoryTabHeight = 96;
	inventoryTabWidth = 440;
	numberOfPlants = 0;
	currency = 0;
	selectedPlant = 0;

	// Initialize plants array with nullptr
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			plants[i][j] = nullptr;
		}
	}

	drag = false;

	// Initialize array of currency values and plant button addresses
	int array_curr[7] = { 100, 50, 100, 200, 25, 175, 150 };
	string address[7] = { "Images/sunflower-button.jpg","Images/wallnut-button.jpg","Images/pea-shooter-button.jpg","Images/repeater-button.jpg","Images/potato-mine-button.jpg","Images/snow-pea-button.jpg","Images/cherry-bomb-button.jpg" };

	// Load inventory textures and set positions
	for (int i = 0; i < 7; i++) {
		inventoryTexture[i].loadFromFile(address[i]);
		inventorySprite[i].setTexture(inventoryTexture[i]);
		inventorySprite[i].setTextureRect(IntRect(0, 0, 59, 82));
		inventorySprite[i].setPosition(266 + i * 59, 32);
	}

	// Initialize plant addresses and prices
	string plantAddresses[] = { "Images/sunflower.png", "Images/wallnut.png", "Images/pea-shooter.png", "Images/repeater.png", "Images/potato-mine.png", "Images/snow-pea.png", "Images/cherry-bomb.png" };
	for (int i = 0; i < 7; i++) {
		inventoryPrice[i] = array_curr[i];
		plantAddress[i] = plantAddresses[i];
	}
}

// Function to draw the inventory on the window
void plantFactory::drawinventory(RenderWindow& window)
{
	for (int i = 0; i < 7; i++) {
		// Check availability and set sprite color accordingly
		if (checkAvaibilty(i))
			inventorySprite[i].setColor(sf::Color(255, 255, 255, 128));
		else
			inventorySprite[i].setColor(sf::Color(255, 255, 255, 255));
		window.draw(inventorySprite[i]);
	}
}

// Function to check if a plant is available for purchase
bool plantFactory::checkAvaibilty(int selectedPlant)
{
	if (currency >= inventoryPrice[selectedPlant]) {
		available = true;
		return false;
	}
	available = false;
	return true;
}

// Function to get a plant from the plants array
plant* plantFactory::getPlant(int i, int j)
{
	return plants[i][j];
}

// Function to get a sprite from the inventory sprites
Sprite plantFactory::getSprites(int i)
{
	return inventorySprite[i];
}

// Function to add plants to the game grid
void plantFactory::addPlants() {

	// Calculate row and column based on current position
	int column = (current_x - 445) / 96;
	int row = (current_y - 220) / 98;
	if (row >= 5) {
		row = 4;
	}

	if (column >= 9) {
		column = 8;
	}

	// Validate placement and add the selected plant
	if (placementValidation(row, column)) {
		return;
	}
	switch (selectedPlant)
	{
	case 0: {
		sunflower* sun = new sunflower("Images/sunflower.png", (column * 88) + 445, (row * 98) + 220);
		plants[row][column] = sun;
		currency -= 100;
		break;
	}
	case 2: {
		peaPlant* pea = new peaPlant("Images/pea-shooter.png", column * 88 + 445, row * 98 + 220);
		plants[row][column] = pea;
		currency -= 100;
		break;
	}
	case 1: {
		wallnut* wall = new wallnut("Images/wallnut.png", (column - 2) * 88 + 445, row * 98 + 220);
		plants[row][column] = wall;
		currency -= 50;
		break;
	}
	case 3: {
		repeater* repeat = new repeater("Images/repeater.png", column * 88 + 445, row * 98 + 220);
		plants[row][column] = repeat;
		currency -= 200;
		break;
	}
	case 4: {
		fumeShroom* fume = new fumeShroom("Images/fumeShroom.png", column * 88 + 445, row * 98 + 220);
		plants[row][column] = fume;
		currency -= 25;
		break;
	}
	case 5: {
		snowPea* snow = new snowPea("Images/snow-Pea.png", column * 88 + 445, row * 98 + 220);
		plants[row][column] = snow;
		currency -= 175;
		break;
	}
	case 6: {
		cherrybomb* cherry = new cherrybomb("Images/cherry-bomb.png", column * 88 + 445, row * 98 + 220);
		plants[row][column] = cherry;
		currency -= 150;
		break;
	}
	default:
		break;
	}
}

// Function to validate placement of plants on the game grid
bool plantFactory::placementValidation(int row, int column) {
	if (current_x < 420 || current_y < 200) {
		return true;
	}
	if (plants[row][column] == nullptr) {
		return false;
	}
	else if (plants[row][column]->getExists() == true)
	{
		return true;
	}

	return false;
}

// Function to remove a plant from the game grid
void plantFactory::removePlant() {
	current_plant->setExists(false);
	delete current_plant;
	current_plant = nullptr;
}

// Function to increase the currency amount
void plantFactory::incCurrency(int i)
{
	currency += i;
}

// Function to get the current currency amount
int plantFactory::getCurrency()
{
	return currency;
}

// Function to deploy plants based on user input
void plantFactory::deploy(const Event& event, RenderWindow& window) {
	if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
		if (event.mouseButton.x < 266 + inventoryTabWidth && event.mouseButton.x >266 && event.mouseButton.y < inventoryTabHeight + 32 && event.mouseButton.y > 32) {

			selectedPlant = (event.mouseButton.x - 266) / 63;
			current_x = Mouse::getPosition(window).x;
			current_y = Mouse::getPosition(window).y;
			if (checkAvaibilty(selectedPlant)) {
				available = true;
				return;
			}

			current_plant = new sunflower(plantAddress[selectedPlant], current_x, current_y);
			drag = true;
		}
	}
	else if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left && drag) {
		this->addPlants();
		drag = false;
	}
	else if (drag) {
		current_x = Mouse::getPosition(window).x;
		current_y = Mouse::getPosition(window).y;
		(*current_plant).setRow(current_x);
		(*current_plant).setColumn(current_y);
		(*current_plant).setPosition(current_x, current_y);
	}
}
