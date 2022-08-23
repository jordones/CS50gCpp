#pragma once
#include "istate.h"

class CountdownState : public IState
{
protected:
  float countdownTimer;
  int countdownValue;
  char countString = '3';
  char *char_ptr;

public:
  CountdownState();
  ~CountdownState();
  void Enter(StateChangeParams params) override;
  void Exit() override;
  void Update(float dt) override;
  void Render() override;
};
