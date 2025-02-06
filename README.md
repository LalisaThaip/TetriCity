# TetriCity OOP Project
A puzzle game that uses tetris style pieces. Written in C++.

## How to build and run (Linux & WSL)

Clone the repository from GitHub:
```bash
git clone --recursive https://github.com/AustinH-adl/OOP-Project
```
```bash
cd OOP-Project
```
```bash
mkdir build
```

Install the required libraries:
```bash
sudo apt install build-essential git clang cmake pkg-config
```
```bash
sudo apt install libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev libwayland-dev libxkbcommon-dev
```

Fix issue with raylib library
```bash
mv src/misc/Rectangle.hpp libs/raylib-cpp/include/Rectangle.hpp
```

Build raylib:
```bash
cd libs/raylib
```
```bash
mkdir build && cd build
```
```bash
cmake -DBUILD_SHARED_LIBS=ON ..
```
```bash
make
```
```bash
sudo make install
```

Build TetriCity:
```bash
cd ../../../build
```
```bash
cmake ..
```
```bash
make
```

Run TetriCity:
```bash
./TetriCity
```
## How to play
When in the game, press play to go to level select or press tutorial to learn more about playing the game.

Once you have selected a level, you can move your current piece by using the arrow key and can rotate it using the 'R' key.

Once in place, press the Enter key to fix the block in place and get a new block.

For each block placed, your score increases. Try and place all of them to win!

You can also use the save and load buttons to save the state of the puzzle and load it again.
