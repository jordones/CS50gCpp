#pragma once
#include "state/states/istate.h"

class PlayState : public IState
{
public:
  PlayState();
  ~PlayState();
  void Enter(StateChangeParams params) override;
  void Exit() override;
  void Update(float dt) override;
  void Render() override;
};
