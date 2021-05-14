#include "game.h"
#include <iostream>
#include <memory>
#include <vector>
#include "opponent.h"
#include "player.h"

void Game::CreateOpponents() {
  std::unique_ptr<Opponent> opponent = std::make_unique<Opponent>();
  opponentlist_.push_back(std::move(opponent));
}

void Game::Init() {
  player_.SetX(400);
  player_.SetY(500);
  CreateOpponents();
  gameScreen_.AddMouseEventListener(*this);
  gameScreen_.AddAnimationEventListener(*this);
}

void Game::UpdateScreen() {
  // Blank rectangle of background color (white)
  gameScreen_.DrawRectangle(0, 0, 800, 600, 255, 255, 255);
  // Player
  if (player_.GetIsActive() == true) {
    player_.Draw(gameScreen_);
  }

  // Opponents
  for (int i = 0; i < opponentlist_.size(); i++) {
    if ((*opponentlist_[i]).GetIsActive() == true) {
      (*opponentlist_[i]).Draw(gameScreen_);
    }
  }

  // Opponent projectiles
  for (int j = 0; j < o_projlist_.size(); j++) {
    if ((*o_projlist_[j]).GetIsActive() == true) {
      (*o_projlist_[j]).Draw(gameScreen_);
    }
  }

  // Player projectiles
  for (int k = 0; k < p_projlist_.size(); k++) {
    if ((*p_projlist_[k]).GetIsActive() == true) {
      (*p_projlist_[k]).Draw(gameScreen_);
    }
  }
}

void Game::OnMouseEvent(const graphics::MouseEvent &mouseEvent) {
  if (mouseEvent.GetMouseAction() == graphics::MouseAction::kMoved ||
      mouseEvent.GetMouseAction() == graphics::MouseAction::kDragged) {
    if (mouseEvent.GetX() > 0 && mouseEvent.GetY() > 0 &&
        mouseEvent.GetX() < gameScreen_.GetWidth() &&
        mouseEvent.GetY() < gameScreen_.GetHeight()) {
      player_.SetX(mouseEvent.GetX() - player_.GetWidth() * (0.5));
      player_.SetY(mouseEvent.GetY() - player_.GetWidth() * (0.5));
    }
  }
}

void Game::OnAnimationStep() {
  MoveGameElements();
  FilterIntersections();
  UpdateScreen();
  gameScreen_.Flush();
}

void Game::FilterIntersections() {
  // Opponent and player
  for (int i = 0; i < opponentlist_.size(); i++) {
    if ((*opponentlist_[i]).IntersectsWith(&player_) == true) {
      (*opponentlist_[i]).SetIsActive(false);
      player_.SetIsActive(false);
      hasLost_ = true;
    }
  }
  // Player projectile and opponents
  for (int j = 0; j < p_projlist_.size(); j++) {
    for (int k = 0; k < opponentlist_.size(); k++) {
      if ((*p_projlist_[j]).IntersectsWith(opponentlist_[k].get())) {
        (*p_projlist_[j]).SetIsActive(false);
        (*opponentlist_[k]).SetIsActive(false);
        score_++;
      }
    }
  }
  // Opponent projectile and player
  for (int h = 0; h < o_projlist_.size(); h++) {
    if (player_.IntersectsWith(o_projlist_[h].get()) == true) {
      (*o_projlist_[h]).SetIsActive(false);
      player_.SetIsActive(false);
      hasLost_ = true;
    }
  }
}

void Game::MoveGameElements() {
  // Opponent moves
  for (int i = 0; i < opponentlist_.size(); i++) {
    if ((*opponentlist_[i]).GetIsActive() == true) {
      (*opponentlist_[i]).Move(gameScreen_);
    }
  }

  // Opponent projectile moves
  for (int j = 0; j < o_projlist_.size(); j++) {
    if ((*o_projlist_[j]).GetIsActive() == true) {
      (*o_projlist_[j]).Move(gameScreen_);
    }
  }

  // Player projectile moves
  for (int k = 0; k < p_projlist_.size(); k++) {
    if ((*p_projlist_[k]).GetIsActive() == true) {
      (*p_projlist_[k]).Move(gameScreen_);
    }
  }
}

void Game::RemoveInactive() {
  for (int i = 0; i < opponentlist_.size(); i++) {
    if ((*opponentlist_[i]).GetIsActive() == false) {
      opponentlist_.erase(opponentlist_.begin() + i);
    }
  }
  for (int k = 0; k < o_projlist_.size(); k++) {
    if ((*o_projlist_[k]).GetIsActive() == false) {
      o_projlist_.erase(o_projlist_.begin() + k);
    }
  }
  for (int h = 0; h < p_projlist_.size(); h++) {
    if ((*p_projlist_[h]).GetIsActive() == false) {
      p_projlist_.erase(p_projlist_.begin() + h);
    }
  }
}

void Game::LaunchProjectiles() {
  for (int i = 0; i < opponentlist_.size(); i++) {
    std::unique_ptr<OpponentProjectile> oprojptr = opponentlist_[i]->LaunchProjectile();
      if (oprojptr == nullptr) {
        return;
      } else {
        o_projlist_.push_back(oprojptr);
      }
  }
}
