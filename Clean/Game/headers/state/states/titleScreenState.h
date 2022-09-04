#pragma once
#include "state/states/istate.h"

class TitleScreenState : public IState
{
public:
  TitleScreenState();
  ~TitleScreenState();
  void Enter(StateChangeParams params) override;
  void Exit() override;
  void Update(float dt) override;
  void Render() override;
};
