#include <fstream>
#include "Textbox.h"

// Default constructor for Textbox object
Textbox::Textbox()
{
}

// Constructor for Textbox object with parameters
Textbox::Textbox(string p, float sizeX, float sizeY, float posX, float posY, float rotate, sf::Color color) : button(p, sizeX, sizeY, posX, posY, rotate, color)
{
}

// Method to set text properties
void Textbox::settext(int size, sf::Color color, int positionX, int positionY)
{
    // Load font
    font2.loadFromFile("Fonts/arial.ttf");
    // Set text properties
    inputText.setFont(font2);
    inputText.setCharacterSize(24);
    inputText.setFillColor(color);
    inputText.setPosition(positionX, positionY);
}

// Method to handle cancel button functionality
bool Textbox::textboxsetcacel(sf::Event event, bool check, sf::Mouse mouse, sf::RenderWindow& window)
{
    // Set cancel button properties
    cancel.setbutton("Images/backbuttoninstruction.png", 160, 50, 420, 470, 0, sf::Color::Transparent);
    cancel.drawbutton(window);

    // Get mouse position
    int posx = sf::Mouse::getPosition(window).x;
    int posy = sf::Mouse::getPosition(window).y;

    // Check if mouse is over cancel button
    if (posx >= cancel.getposX() && posx <= cancel.getposX() + cancel.getsizeX() && posy >= cancel.getposY() && posy <= cancel.getposY() + cancel.getsizeY())
    {
        // Check if mouse button is pressed
        if (event.type == sf::Event::MouseButtonPressed)
        {
            check = false; // Set check to false
        }
    }
    return check;
}

// Method to handle OK button functionality
bool Textbox::textboxsetok(sf::Event event, bool check, sf::Mouse mouse, sf::RenderWindow& window)
{
    // Set OK button properties
    ok.setbutton("Images/backbuttoninstruction.png", 160, 50, 220, 470, 0, sf::Color::Transparent);
    ok.drawbutton(window);

    // Get mouse position
    int posx = sf::Mouse::getPosition(window).x;
    int posy = sf::Mouse::getPosition(window).y;

    // Check if inputString has enough characters
    if (inputString.length() >= 5) {
        // Check if Enter key is pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            check = false; // Set check to false
        }

        // Check if mouse is over OK button
        if (posx >= ok.getposX() && posx <= ok.getposX() + ok.getsizeX() && posy >= ok.getposY() && posy <= ok.getposY() + ok.getsizeY())
        {
            // Check if mouse button is pressed
            if (event.type == sf::Event::MouseButtonPressed)
            {
                check = false; // Set check to false
            }
        }
    }
    return check;
}

// Method to handle text input
void Textbox::writetext(sf::Event event)
{
    // Check if a character is entered
    if (event.type == sf::Event::TextEntered)
    {
        // Check if inputString length is within limit
        if (inputString.length() <= 25)
        {
            // Add character to inputString
            if (event.text.unicode < 128 && event.text.unicode != 8)
            {
                inputString += static_cast<char>(event.text.unicode);
                inputText.setString(inputString + "|");
            }
            // Remove character if backspace is pressed
            if (inputString.length() > 0)
            {
                if (event.text.unicode == 8)
                {
                    string oldtext = inputString;
                    string newtext = "";
                    for (int i = 0; i < oldtext.length() - 1; i++) {
                        newtext += oldtext[i];
                    }
                    inputString = newtext;
                    inputText.setString(inputString + "|");
                }
            }
        }
    }
}

// Method to save input to file
void Textbox::save(sf::Event event, sf::Mouse mouse, sf::RenderWindow& window)
{
    // Get mouse position
    int posx = sf::Mouse::getPosition(window).x;
    int posy = sf::Mouse::getPosition(window).y;

    // Check if Enter key is pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        // Open file for writing
        ofstream save("name.txt", ios::in | ios::app);
        if (!save.is_open()) {
            cout << "Error while input opening file " << endl;
        }

        // Save inputString to file
        save << inputString << endl;
        save.close();
    }

    // Check if mouse is over OK button
    if (posx >= ok.getposX() && posx <= ok.getposX() + ok.getsizeX() && posy >= ok.getposY() && posy <= ok.getposY() + ok.getsizeY())
    {
        // Check if mouse button is pressed
        if (event.type == sf::Event::MouseButtonPressed)
        {
            // Open file for writing
            ofstream save("name.txt", ios::in | ios::app);
            if (!save.is_open()) {
                cout << "Error while input opening file " << endl;
            }

            // Save inputString to file
            save << inputString << endl;
            save.close();
        }
    }
}

// Method to display saved text from file
void Textbox::showscore(sf::RenderWindow& window)
{
    // Set text properties
    sf::Text name;
    sf::Font font;
    font.loadFromFile("Fonts/arial.ttf");
    name.setFont(font);

    // Open file for reading
    ifstream show("name.txt", ios::out);
    if (!show.is_open()) {
        cout << "Error while opening output file " << endl;
    }

    string output;
    int x = 1;
    name.setCharacterSize(28);
    name.setPosition(400, 330);
    name.setFillColor(sf::Color::Red);
    name.setStyle(sf::Text::Bold);
    name.setOutlineColor(sf::Color::Black);
    name.setOutlineThickness(5);

    // Read lines from file and display on window
    while (getline(show, output)) {
        name.setPosition(300, 300 + x);
        name.setString(output);
        x += 100;
        window.draw(name);
    }
    show.close();
}

// Method to draw input text on window
void Textbox::drawtext(sf::RenderWindow& window)
{
    window.draw(inputText);
}
