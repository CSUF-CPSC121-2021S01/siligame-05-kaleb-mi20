#include "opponent.h"

void Opponent::Draw(graphics::Image &image) {
  image.DrawRectangle(17 + x_, 34 + y_, 20, 7, 155, 155, 155);
  image.DrawRectangle(10 + x_, 14 + y_, 34, 20, 155, 155, 155);
  image.DrawRectangle(17 + x_, 7 + y_, 20, 7, 155, 155, 155);
  image.DrawRectangle(10 + x_, 23 + y_, 34, 3, 60, 60, 60);
  image.DrawRectangle(28 + x_, 29 + y_, 16, 3, 60, 60, 60);
  image.DrawRectangle(10 + x_, 16 + y_, 16, 3, 60, 60, 60);
  image.DrawCircle(33 + x_, 18 + y_, 4, 60, 60, 60);
}

void OpponentProjectile::Draw(graphics::Image &image) {
  image.DrawRectangle(0 + x_, 0 + y_, 5, 5, 220, 0, 0);
}

void Opponent::Move(const graphics::Image &image) {
  SetX(x_ + 1);
  SetY(y_ + 1);
  if (GameElement::IsOutOfBounds(image) == true) {
    GameElement::SetIsActive(false);
  }
}

void OpponentProjectile::Move(const graphics::Image &image) {
  SetX(x_ + 3);
  if (GameElement::IsOutOfBounds(image) == true) {
    GameElement::SetIsActive(false);
  }
}

std::unique_ptr<class OpponentProjectile> Opponent::LaunchProjectile() {
  if (counter % 20 == 0) {
    counter++;
    return std::make_unique<OpponentProjectile>(GetX() + 20, GetY() + 20);
  }
  return nullptr
}
