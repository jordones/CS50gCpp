#pragma once
#include "istate.h"

class ScoreState : public IState
{
public:
  ScoreState();
  ~ScoreState();
  void Enter(StateChangeParams params) override;
  void Exit() override;
  void Update(float dt) override;
  void Render() override;
};
