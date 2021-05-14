#ifndef OPPONENT_H
#define OPPONENT_H

#include <memory>
#include "cpputils/graphics/image.h"
#include "game_element.h"

class Opponent : public GameElement {
 public:
  // Constructors
  Opponent() : GameElement(0, 0, 50, 50) {}
  Opponent(const int &x, const int &y) : GameElement(x, y, 50, 50) {}

  void Draw(graphics::Image &image);
  void Move(const graphics::Image &image);
  std::unique_ptr<class OpponentProjectile> LaunchProjectile();
};

class OpponentProjectile : public GameElement {
 public:
  // Constructors
  OpponentProjectile() : GameElement(0, 0, 5, 5) {}
  OpponentProjectile(const int &x, const int &y) : GameElement(x, y, 5, 5) {}

  void Draw(graphics::Image &image) override;
  void Move(const graphics::Image &image) override;
};

#endif
