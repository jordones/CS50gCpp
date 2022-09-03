#pragma once

#include "istate.h"
#include "stateFactory.h"
#include <vector>

class StateMachine
{
protected:
  StateFactory factory;

public:
  std::vector<IState *> states;
  IState *current;

  StateMachine();
  ~StateMachine();
  void PushState(IState *state);
  void Change(StateName stateName, StateChangeParams params);
  void Update(float dt);
  void Render();
};
