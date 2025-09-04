# Nine Men’s Morris in C

A classic **Nine Men’s Morris** game implementation in C, using **bit manipulation** to represent the board.  
This project is aimed at developers who want to explore game logic, bitwise operations, and simple C structures.

---

## Project Goal

- Create a complete **two-player console game**.  
- Represent the board with **24-bit integers**, where each bit corresponds to a board position.  
- Support the main game phases:
  1. Placing pieces.
  2. Moving pieces.
  3. Removing opponent’s pieces when forming mills.

---

## How It Works

Each player has:
- `board` → an integer indicating occupied positions (bits = 1) or empty positions (bits = 0).  
- `offboard` → pieces still not placed on the board.  

Key functions:
- `setbit()` / `getbit()` → manipulate individual bits.  
- `validmove()` → validate adjacent moves and game rules.  
- `canputpiece()` → check if a position is free.  
- `checktriplets()` → detect mills formed.  

The game ends when a player has less than 3 pieces.

---

## How to Play

1. Compile the project:
   ```bash
   gcc morris.c ninemens.c -o ninemens
