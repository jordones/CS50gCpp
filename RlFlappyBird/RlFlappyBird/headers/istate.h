#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "raylib.h"

enum StateName {
  Empty,
  Play
};

struct StateChangeParams {
  int score;
  bool isPaused;
};

class IState {
public:
  StateName name;
  virtual void Enter(StateChangeParams params) = 0;
  virtual void Exit() = 0;
  virtual void Update(float dt) = 0;
  virtual void Render() = 0;
};

class EmptyState : public IState {
  float timeElapsed = 0.0f;
  int seconds = 0;
public:
  EmptyState() {
    name = Empty;
  }
  void Enter(StateChangeParams params) override {
    std::cout << "Entered EmptyState" << std::endl;
  }
  void Exit() override {
    std::cout << "Exited EmptyState" << std::endl;
  }
  void Update(float dt) override {
    timeElapsed += dt;
    if (timeElapsed > 1) {
      seconds++;
      timeElapsed = 0.0f;
      std::cout << "EmptyState Seconds: " << seconds << std::endl;
    } 
  }
  void Render() override {
    DrawText("Empty State", 20, 30, 16, BLACK);
  }
};
