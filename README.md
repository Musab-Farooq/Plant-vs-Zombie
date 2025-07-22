# 🧟🌻 Plants vs. Zombies 

A fun and strategic **tower-defense** style game developed in **C++** using the **SFML** (Simple and Fast Multimedia Library). In this simplified version of the classic *Plants vs. Zombies*, protect your home from waves of quirky zombies by tactically placing powerful plants on your lawn!

---

## 🎮 Gameplay Overview

- 🌱 **Place Plants**: Choose from Sunflowers, Peashooters, Wall-nuts, Cherry Bombs, and more!
- ☀️ **Collect Sun Points**: Earn sun by planting Sunflowers — the currency for deploying new plants.
- 🧟 **Defend Your Home**: Stop waves of zombies like Normal, Football, and Flying Zombies before they reach your house.
- ❄️ **Special Attacks**: Use Freezing Peas, Exploding Bombs, and Thick Wall-nuts to hold the line.

---

## ✨ Features

### 🧩 Game Mechanics
- **Grid-Based Lawn**: Place plants on a 5x9 tile grid.
- **Zombie Waves**: Increasing number of zombies with each level.
- **Plant Variety**:
  - **Sunflower** – Generates suns
  - **Peashooter / Repeater / Snow Pea** – Shoot bullets (some freeze zombies)
  - **Wallnut** – Defensive tank
  - **Cherry Bomb** – Explodes in a 3x3 area
  - **Fume Shroom** – Placeholder (expandable)
- **Zombie Types**:
  - Normal, Dancing, Football, Flying (each with unique movement and health)

### 🧠 Game Logic
- Bullet-Zombie collision detection
- Sun currency and plant placement handling
- Delayed wave-based zombie spawning
- Game ends on zombie house entry or zombie elimination

---

## 🖥️ User Interface

- **Main Menu**: Start game, view instructions, or high scores
- **Textbox**: Enter your name (saved to `name.txt`) for high score tracking
- **Pause Functionality**: Freeze plant and zombie actions temporarily
- **Instruction Screen**: Understand plant types and gameplay basics

---

## 🗂️ Project Structure

### 🔧 Core Classes
| Component         | Description |
|------------------|-------------|
| `plant`          | Abstract base class for all plants |
| `zombie`         | Base class for all zombies |
| `bullet`         | Handles bullet behavior and effects |
| `plantFactory`   | Controls inventory, sun points, and plant deployment |
| `zombieFactory`  | Spawns zombies by wave and level |

### 🌱 Plant Derived Classes
- `sunflower`, `peaPlant`, `repeater`, `snowPea`, `wallnut`, `cherrybomb`, `fumeShroom`

### 🧟 Zombie Derived Classes
- `normalZombie`, `dancingZombie`, `footballZombie`, `flyingZombie`

### 📋 UI Classes
- `screens`, `mainmenu`, `startingscreen`, `Textbox`, `buttons`

---

## 📁 Assets & Dependencies

- **🖼️ Images**: Located in `Images/` (plants, zombies, buttons, backgrounds)
- **🔤 Fonts**: Arial (`Fonts/arial.ttf`)
- **⚙️ C++ Libraries**: SFML 2.x, Standard Library (for file I/O and utilities)

---

## ▶️ How to Play

1. **Launch Game**:
   - Start from `startingscreen`
2. **Main Menu**:
   - Choose to play, read instructions, or view high scores
3. **Place Plants**:
   - Select from top bar and click on lawn tiles
4. **Defend**:
   - Prevent zombies from reaching the left side
5. **Win**:
   - Clear all zombie waves
6. **High Score**:
   - Enter your name to save in `name.txt`

---

## ⚠️ Limitations

- Some zombie/plant behaviors are placeholders or incomplete
- No advanced animation or sound support
- Limited error handling (e.g., missing assets or `name.txt`)
- No game-over screen yet

---

## 🚀 Future Improvements

- 🎵 Add sound effects and music using SFML Audio
- 🤖 Complete behavior for all zombie/plant types
- 🏆 Add multi-level progression and score tracking
- 📉 Better animations and transitions
- ⚠️ Error prompts for missing files/assets

---

## 💾 Installation & Requirements

### 🛠️ Requirements
- SFML 2.x installed and linked
- C++17 compatible compiler (e.g., g++, MSVC)

### 🧪 Quick Run Option
> To play the game **without installing SFML**, simply download the **release ZIP** and run the `PlantsVsZombies.exe` file inside.

---


