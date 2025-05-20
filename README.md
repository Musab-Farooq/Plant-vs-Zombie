# Plants vs. Zombies Clone
Overview
This project is a C++ implementation of a simplified version of the Plants vs. Zombies game using the SFML (Simple and Fast Multimedia Library) framework. The game features a grid-based lawn where players strategically place plants to defend against waves of zombies. Players collect sun points as currency to deploy plants, each with unique abilities, while zombies advance in waves with varying characteristics. The game includes multiple screens (main menu, level selection, instructions, and high score display) and supports basic gameplay mechanics like plant placement, zombie movement, and collision detection.

Features
Gameplay Mechanics:
Players place plants (e.g., Sunflower, Peashooter, Wallnut, Repeater, Snow Pea, Cherry Bomb, Fume Shroom) on a 5x9 grid to combat zombies.
Zombies (Normal, Dancing, Football, Flying) spawn in waves, with different speeds and health levels depending on the game level.
Sun points are collected from Sunflowers to purchase plants.
Plants shoot bullets (e.g., peas, snow peas) or perform special actions (e.g., explode, block zombies).
Collision detection between bullets, plants, and zombies, including special effects like freezing or explosions.

User Interface:
Main menu with options for starting the game, viewing instructions, or checking high scores.
Textbox for entering player names, saved to a file (name.txt) for high score tracking.
Pause functionality to halt plant and zombie actions.

Levels and Progression:
Supports multiple levels with increasing zombie counts (10 per level).
Waves of zombies are deployed with a delay, and the game ends when all zombies are defeated or reach the player's house.

Graphics and Animations:
Uses SFML for rendering sprites and textures for plants, zombies, bullets, and UI elements.
Basic animations for zombies (e.g., walking cycles) and plants (e.g., Sunflower sun production).
Project Structure
The project is organized into several key classes, each handling specific game components:

Core Classes:
plant (base class): Defines common plant properties (position, life, sprite, bullets) and abstract methods for drawing and functionality.
Zombie (base class): Defines common zombie properties (position, life, speed, sprite) and abstract methods for functionality.
bullet: Manages projectile behavior (position, speed, type) for plants like Peashooter and Snow Pea.
plantFactory: Manages plant placement, inventory, and sun currency.
zombieFactory: Manages zombie creation and wave deployment based on the game level.
Plant Classes (derived from plant):
sunflower: Produces collectable sun points every few seconds.
peaPlant, repeater, snowPea: Shoot projectiles (peas or snow peas) to damage or slow zombies.
wallnut: Acts as a defensive barrier with high health.
cherrybomb: Explodes to deal area damage to zombies.
fumeShroom: Likely a placeholder or incomplete plant (no unique functionality in provided code).
Zombie Classes (derived from Zombie):
normalZombie: Basic zombie with standard movement and health.
dancingZombie, footballZombie, flyingZombie: Specialized zombies with unique behaviors (though some implementations are incomplete in the provided code).

UI Classes:
screens: Base class for rendering game screens (e.g., menus, level selection).
mainmenu, startingscreen: Handle menu navigation and level/instruction selection.
Textbox: Manages player name input and high score display.
buttons: Handles interactive buttons for menus and text input.

Dependencies
SFML 2.x: Required for graphics, window management, and event handling.
C++ Standard Library: For file I/O (name.txt for high scores) and general utilities.
Fonts: Arial font (Fonts/arial.ttf) for text rendering.
Images: Various PNG files in the Images/ directory for sprites (e.g., plants, zombies, buttons, backgrounds).

Usage
Launch the game to access the starting screen.
Click the start button to proceed to the main menu.
From the main menu:
Select a level to start the game.
View instructions for gameplay details.
Check high scores to see saved player names.

In-game:
Click Sunflowers to collect sun points.
Select plants from the inventory (top bar) and place them on the grid by clicking.
Zombies spawn from the right and move left; plants automatically attack.
Survive all zombie waves to win the level.
Enter your name in the textbox for high score tracking (saved to name.txt).

Limitations
Some zombie types (dancingZombie, footballZombie, flyingZombie, fumeShroom) lack complete implementations in the provided code.
No explicit game-over screen or multi-level progression logic is fully implemented.
Limited error handling for file I/O (e.g., missing name.txt or image files).
No sound or music support.
Animations are basic and rely on texture switching.
Future Improvements
Implement missing zombie and plant functionalities (e.g., unique behaviors for Dancing and Flying Zombies).
Add sound effects and background music using SFML audio.
Enhance UI with animations and better visual feedback.
Implement a game-over screen and multi-level progression.
Add error handling for missing assets or file access issues.

NOTE: To play the game without setting up SFML in your system just download the zip file and run exe file from there
