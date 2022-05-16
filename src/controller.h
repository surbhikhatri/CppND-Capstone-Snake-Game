#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Game;

class Controller
{
public:
  // receive a game and snake object reference.
  void HandleInput(bool &running, Snake &snake, Game &game) const;
  void IncreaseGrowth(Snake::Direction input);

private:
  void ChangeDirection(Snake &snake, Snake::Direction input, Snake::Direction opposite) const;
};

#endif