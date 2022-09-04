#pragma once
#include "state/states/istate.h"

class CountdownState : public IState
{
protected:
  float timeElapsed;
  int secondsElapsed = 0;
  char countString = '3';

public:
  CountdownState();
  ~CountdownState();
  void Enter(StateChangeParams params) override;
  void Exit() override;
  void Update(float dt) override;
  void Render() override;
};
