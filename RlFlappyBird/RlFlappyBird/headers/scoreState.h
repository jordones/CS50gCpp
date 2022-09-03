#pragma once
#include "istate.h"

class ScoreState : public IState
{
protected:
  int score = 0;

public:
  ScoreState();
  ~ScoreState();
  void Enter(StateChangeParams params) override;
  void Exit() override;
  void Update(float dt) override;
  void Render() override;
};
