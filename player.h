#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "cpputils/graphics/image.h"
#include "game_element.h"
#include "opponent.h"

class Opponent;
class OpponentProjectile;

class Player : public GameElement {
 public:
  // Constructor
  Player() : GameElement(0, 0, 50, 50) {}
  Player(const int &x, const int &y) : GameElement(x, y, 50, 50) {}

  void Draw(graphics::Image &image);
  void Move(const graphics::Image &image);
};

class PlayerProjectile : public GameElement {
 public:
  // Constructor
  PlayerProjectile() : GameElement(0, 0, 5, 5) {}
  PlayerProjectile(const int &x, const int &y) : GameElement(x, y, 5, 5) {}

  void Draw(graphics::Image &image) override;
  void Move(const graphics::Image &image) override;
};

#endif
