#pragma once
#include "state/states/istate.h"

class ScoreState : public IState
{
protected:
  int score;

public:
  ScoreState();
  ~ScoreState();
  void Enter(StateChangeParams params) override;
  void Exit() override;
  void Update(float dt) override;
  void Render() override;
};
