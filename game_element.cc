#include "game_element.h"
#include <iostream>

bool GameElement::IntersectsWith(GameElement* element2) {
  // element 1
  int element1_xZone = GetX() + GetWidth();
  int element1_yZone = GetY() + GetHeight();
  // element 2
  int element2_xZone = (*element2).GetX() + (*element2).GetWidth();
  int element2_yZone = (*element2).GetY() + (*element2).GetWidth();

  // Checking for overlap
  if (GetX() < element2_xZone) {
    if ((*element2).GetX() < element1_xZone) {
      if (GetY() < element2_yZone) {
        if ((*element2).GetY() < element1_yZone) {
          return true;
        }
      }
    }
  }
  return false;
}

bool GameElement::IsOutOfBounds(const graphics::Image& image) {
  // out of bounds on the left or right boundary
  if (x_ < 0 || (x_ + width_) > image.GetWidth()) {
    return true;
  }
  // out of bounds on the top or bottom boundary
  if (y_ < 0 || (y_ + height_) > image.GetHeight()) {
    return true;
  }
  return false;
}
