# so_long 🕹️

## Overview

`so_long` is a 2D game developed as part of the 42 Curriculum, created with the `minilibx` graphics library. This project provides a fun and interactive gaming experience, focusing on custom map generation, dynamic gameplay mechanics. The game also incorporates visual effects, player movement, and various game states for an enhanced user experience.

## Video Demonstration
For a visual demonstration of how the `so_long` program works, you can watch the video below:

![](https://github.com/rh-oussama/so_longo-42/blob/main/so_long_demo.gif)

## 🎮 Features

- **Custom Map Loading**: Supports loading maps in the `.ber` file format, allowing users to design and implement their own game levels.
- **Player Character**: Navigate a player through the map using keyboard controls.
- **Ghost Enemies**: Enemies that actively chase the player. If they hit you, you die.
- **Collectible Items**: Items that can be collected for extra points or gameplay progression.
- **Animated Sprites**: Includes animated sprites for players, enemies, and objects to enhance the visual appeal.
- **Cross-Platform Support**: Works on both Linux and MacOS environments.
- **Graphics & Visuals**: Built using the `minilibx` library, designed to be lightweight and fast.

## 🚀 Installation

To get started with `so_long`, follow these steps:

### 1. Install MLX

Before you can run `so_long`, you'll need to install the MinilibX library. Follow these steps to install it:

- **Install dependencies**:

    ```bash
    sudo apt-get update
    sudo apt-get install libx11-dev libxext-dev libbsd-dev
    ```

- **Download MinilibX**:

    ```bash
    git clone https://github.com/42Paris/minilibx-linux.git
    ```

- **Navigate to the downloaded directory**:

    ```bash
    cd minilibx-linux
    ```

- **Compile the library**:

    ```bash
    make
    ```

- **Install the library**:

    ```bash
    sudo cp mlx.h /usr/include
    sudo cp libmlx.a /usr/lib
    ```

### 2. Clone the Repository & compile

Clone the `so_long` repository and navigate into the project directory:

```bash
git clone git@github.com:rh-oussama/so_longo-42.git
cd so_long
make
```

### 3. Run the Game

Once the project is compiled, you can run the game by executing the following command:

```bash
./so_long <map_path>
```
