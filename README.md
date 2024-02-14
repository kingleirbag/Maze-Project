<h1 align="center">
	Maze Project
</h1>

## Table of Contents

- Maze project
  * [Features](#features)
  * [Installation](#installation)
  * [Map Configuration](#map-configuration)
  * [Gameplay](#gameplay)
  * [Contributing](#contributing)

This is Maze, a 3D first-person shooter game developed in C using the old-school graphics library, Minilibx. Inspired by classic games like Wolfenstein and Doom, Maze brings back the nostalgia of the golden age of gaming with its raycasting technique to render the environment, complete with walls, enemies, and objects.

## Features

- Immersive first-person gameplay with raycasting rendering technique.
- Intricately designed levels featuring walls, floors, and ceilings.
- A variety of enemies, each with distinct abilities and characteristics, adding challenges to your adventure.
- Explore interactive doors, static and animated objects that enhance the gameplay experience.
- Classic retro-inspired visuals that evoke the essence of early 3D games.

## Installation

1. Clone the repository:
```bash
git https://github.com/kingleirbag/Maze-Project.git; cd Maze-Project
```

2. Compile the game:
```bash
make bonus
```

3. Run the game:
```bash
./maze_bonus bonus/maps/map.cub
```

## Map Configuration

Map data is stored as `.cub` file. You can check [this file](bonus/maps/map.cub) for a quick example.

Also, use `make help` to know what are the characters you can use in the map configuration.

## Gameplay

- **W, A, S, D:** to move around
- **Mouse:** to rotate the player's view
- **Left Click:** Shoot
- **E:** to open a door
- **M:** to toggle map display
- **1 - 2:** to change current weapon (only available/collected ones)

