# Game Of Life

## Overview

This project simulates Conway's Game of Life in a terminal environment. Users can interact with the game using commands to:

- Set the grid size and initial configurations
- Run the simulation
- Randomize initial cells
- Observe population and generation counts

## Getting Started

### Prerequisites

- C++17 compatible compiler
- Cmake 3.23+

### Build Instructions

```bash
git clone https://github.com/ZhengOwen888/Game-of-Life.git
cd Game-of-Life
mkdir build
cd build
cmake ..
make
```

### Run the Game

```bash
./main
```

## Commands

```bash
#== GOL Command Info ==#

Description: Set game options and settings.
      Usage: gol set [options] <args>
    Example: gol set --resize 10 20 --generation 100
    Options:
      [-rs|--resize]: resize grid size.
      [-g|--generation]: set max generations.
      [-dms|--delay-ms]: set time for each generation in ms.
      [-ap|--alive-prob]: set the probability a cell is alive.
      [-cr|--cell-repr]: set the character that represent an alive cell.
      [-cs|--cell-status]: set the status of the cell in the grid.


Description: run the game.
      Usage: gol run [options] <args>
    Example: gol run
    Options:


Description: Quit the game.
      Usage: gol quit [options] <args>
    Example: gol quit
    Options:


Description: randomly set cells for the current game configuration.
      Usage: gol rand-init [options] <args>
    Example: gol rand-init
    Options:
```
