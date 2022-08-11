#pragma once

#include "istate.h"
#include <vector>

class StateMachine {
public:
  std::vector<IState*> states;
  IState* current;
  
  StateMachine();
  ~StateMachine();
  void PushState(IState* state);
  void Change(StateName stateName, StateChangeParams params);
  void Update(float dt);
  void Render();
};
