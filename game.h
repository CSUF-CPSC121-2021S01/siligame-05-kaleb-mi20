#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <vector>
#include "cpputils/graphics/image.h"
#include "cpputils/graphics/image_event.h"
#include "game_element.h"
#include "opponent.h"
#include "player.h"

class Game : graphics::AnimationEventListener, graphics::MouseEventListener {
 public:
  // Constructors
  Game() { gameScreen_.Initialize(800, 600); }
  Game(const int &width, const int &height) {
    gameScreen_.Initialize(width, height);
  }

  // Getters and Setters
  graphics::Image &GetGameScreen() { return gameScreen_; }

  std::vector<std::unique_ptr<Opponent>> &GetOpponents() {
    return opponentlist_;
  }

  std::vector<std::unique_ptr<OpponentProjectile>> &GetOpponentProjectiles() {
    return o_projlist_;
  }

  std::vector<std::unique_ptr<PlayerProjectile>> &GetPlayerProjectiles() {
    return p_projlist_;
  }

  Player &GetPlayer() { return player_; }

  // Member functions
  void CreateOpponents();
  void CreateOpponentProjectiles();
  void CreatePlayerProjectiles();
  void Init();
  void UpdateScreen();
  void Start() { gameScreen_.ShowUntilClosed(); }
  void OnMouseEvent(const graphics::MouseEvent &event);
  void OnAnimationStep();
  void FilterIntersections();
  void MoveGameElements();
  void RemoveInactive();
  void LaunchProjectiles();
  int GetScore() const { return score_; }
  bool HasLost() const { return hasLost_; }

 private:
  int score_ = 0;
  bool hasLost_ = false;
  graphics::Image gameScreen_;
  std::vector<std::unique_ptr<Opponent>> opponentlist_;
  std::vector<std::unique_ptr<OpponentProjectile>> o_projlist_;
  std::vector<std::unique_ptr<PlayerProjectile>> p_projlist_;
  Player player_;
};

#endif
