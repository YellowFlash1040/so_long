# so_long

A small 2D game built in C using the [MLX](https://github.com/42paris/minilibx-linux) library
where the player navigates through a map collecting items and reaching the exit.

This project is part of the [Codam](https://www.codam.nl/en/) curriculum, [42 School](https://42.fr/en/homepage/) campus, and demonstrates proficiency in C programming, using graphics libraries, and handling user input.

## Prerequisites:

Before building the project, ensure you have the following installed:

- GNU Make
- GNU Compiler Collection (GCC)
- X11 development libraries
- libbsd

Install missing prerequisites on Debian/Ubuntu-based systems:

```bash
sudo apt update && sudo apt install make libx11-dev libxext-dev gcc libbsd-dev
```

## Installation

1. Clone the repository:

```bash
git clone https://github.com/YellowFlash1040/so_long.git
cd so_long
```

2. Build the project:

```bash
make
```

This will create an executable named so_long in the project directory.

## Usage

Run the game with a map file as an argument:

```bash
./so_long maps/classic.ber
```

- **Arrow keys / WASD**: Move the player
- **ESC / Close window**: Quit the game

Maps must be in `.ber` format and follow the game rules: surrounded by walls, contain a player start position, collectible items, and an exit.
