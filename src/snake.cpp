#include "snake.h"
#include <cmath>
#include <iostream>

void Snake::Update(bool *fence, bool *energy_bar) {
  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(
          head_y)};  // We first capture the head's cell before updating.
  UpdateHead(fence);
  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)};  // Capture the head's cell after updating.

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
    UpdateBody(current_cell, prev_cell, energy_bar);
  }
}

void Snake::UpdateHead(bool *fence) {
  switch (direction) {
    case Direction::kUp:
      head_y -= speed;
      break;

    case Direction::kDown:
      head_y += speed;
      break;

    case Direction::kLeft:
      head_x -= speed;
      break;

    case Direction::kRight:
      head_x += speed;
      break;
  }

  // check if the wall is active
  if(*fence){
    // check if snake hit the wall
    if(head_x > 32 || head_y > 32 || head_x < 0 || head_y < 0){
      std::cout << "you hit the fence" << std::endl;
      alive = false;
      // show a dialog box
      std::string msgText{"Score: " + std::to_string(*_score) + "\n Size: " + std::to_string(size)};
      SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "You died because you touched the fence!", msgText.c_str(), NULL);
    }    
  }else{
    // Wrap the Snake around to the beginning if going off of the screen.
    // if there is no wall
    head_x = fmod(head_x + grid_width, grid_width);
    head_y = fmod(head_y + grid_height, grid_height);
  }
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell, bool *energy_bar) {
  // Add previous head location to vector
  body.push_back(prev_head_cell);

  if (!growing) {
    // Remove the tail from the vector.
    body.erase(body.begin());
  } else {
    growing = false;
    size++;
  }

  // Check if the snake has died.
  for (auto const &item : body) {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
      alive = false;
      // show a dialog box
      std::string msgText{"Score: " + std::to_string(*_score) + "\n Size: " + std::to_string(size)};
      SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "You died because you touched yourself :P !", msgText.c_str(), NULL);
    }
  }
}

void Snake::GrowBody() { growing = true; }

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y) {
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
    return true;
  }
  for (auto const &item : body) {
    if (x == item.x && y == item.y) {
      return true;
    }
  }
  return false;
}