# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

In this project I extended the [Snake Game](https://github.com/udacity/CppND-Capstone-Snake-Game) by following the principles I learned throughout the c++ Nanodegree Program. See [Rubric Points](#rubric-points)

## New Features
* Pause
  * Game can be **paused/resumed** by pressing `ESC` button.  

* Energy Bar
  * There is a 30% chance for a food to be an energy bar.
  * Energy Bars are unidentified until eaten and if snake eats and energy bar, the food it will consume in next 10 sec will have double points, hence 2x size growth.

* Added modal box functionality
  * When we die, a small dialog box will appears and show the score, size and the reaons of death in the modal. 

* There is a **fence** option available. 
  * Pressing the `f` key will enable/disable the fence around the game window. 
  * Touching the fence will result in the death of the snake.

* Take a Break!
  * User can take **break** or **continue** by pressing `b` button.  

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Rubric Points

### Loops, Functions, I/O
The project code is clearly organized into functions and classes. All funtions follow single responsibilty principle and can be reused.

Project accept user inputs during the game, these inputs are used by controlling the snake and other game features such as pausing and triggering the wall.

### Object Oriented Programming
- The project uses Object Oriented Programming techniques.
  - The project code is organized into classes having it's own data members and menber functions.
- Classes use appropriate access specifiers for class members.
  - Please visit the `src` folder and take a look.
- Class constructors utilize member initialization lists.
  - Examples include [game.cpp](./src/game.cpp#L9).
- Classes follow an appropriate inheritance hierarchy.
  - Examples include use of friend classes.

### Memory Management
- The project makes use of references in function declarations.
  - Examples include [game.h](./src/game.h#L42) and [controller.h](./src/controller.h#L12).
- The project uses destructors appropriately.
  - Examples include [renderer.h](./src/renderer.h#L12).

### Concurrency
The project creates a thread each time snake eats energy bas. This thread waits for 10 seconds and return back the snake's to normal by modifying the game's private pointer variable.
