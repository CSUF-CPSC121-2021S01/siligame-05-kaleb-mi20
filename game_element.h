#ifndef GAME_ELEMENT_H
#define GAME_ELEMENT_H

#include "cpputils/graphics/image.h"

class GameElement {
 public:
  // Constructors
  GameElement() : x_(0), y_(0), width_(50), height_(50) {}
  GameElement(const int &x, const int &y, const int &width, const int &height)
      : x_(x), y_(y), width_(width), height_(height) {}

  // Getters and Setters
  int GetX() const { return x_; }
  int GetY() const { return y_; }
  void SetX(const int &x) { x_ = x; }
  void SetY(const int &y) { y_ = y; }
  int GetWidth() const { return width_; }
  int GetHeight() const { return height_; }
  bool GetIsActive() const { return isActive_; }
  void SetIsActive(bool active) { isActive_ = active; }

  virtual void Draw(graphics::Image &image) = 0;
  virtual void Move(const graphics::Image &image) = 0;
  bool IntersectsWith(GameElement* element2);
  bool IsOutOfBounds(const graphics::Image &image);

 protected:
  int x_;
  int y_;
  int width_;
  int height_;
  bool isActive_ = true;
};

#endif
