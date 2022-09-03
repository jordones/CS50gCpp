#pragma once

#include "istate.h"
#include "stateFactory.h"
#include <vector>

class StateMachine
{
protected:
  StateFactory factory;

public:
  IState *current;

  StateMachine();
  ~StateMachine();
  void Change(StateName stateName, StateChangeParams params);
  void Update(float dt);
  void Render();
};
