#include "player.h"
#include "game_element.h"

void Player::Draw(graphics::Image &image) {
  image.DrawRectangle(22 + x_, 27 + y_, 8, 9, 220, 0, 0);
  image.DrawRectangle(5 + x_, 27 + y_, 9, 9, 220, 0, 0);
  image.DrawRectangle(39 + x_, 27 + y_, 8, 9, 220, 0, 0);
  image.DrawRectangle(12 + x_, 27 + y_, 10, 9, 90, 90, 90);
  image.DrawRectangle(30 + x_, 27 + y_, 9, 9, 90, 90, 90);
  image.DrawRectangle(5 + x_, 23 + y_, 42, 4, 90, 90, 90);
  image.DrawRectangle(5 + x_, 36 + y_, 42, 4, 90, 90, 90);
  image.DrawRectangle(12 + x_, 19 + y_, 27, 4, 0, 150, 255);
  image.DrawRectangle(14 + x_, 15 + y_, 23, 4, 0, 150, 255);
  image.DrawRectangle(16 + x_, 11 + y_, 19, 4, 0, 150, 255);
}

void PlayerProjectile::Draw(graphics::Image &image) {
  image.DrawRectangle(0 + x_, 0 + y_, 5, 5, 0, 220, 0);
}

void Player::Move(const graphics::Image &image) {}

void PlayerProjectile::Move(const graphics::Image &image) {
  SetX(x_ + 3);
  if (GameElement::IsOutOfBounds(image) == true) {
    GameElement::SetIsActive(false);
  }
}
