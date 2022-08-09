#include "stateMachine.h"

StateMachine::StateMachine() {
  states.push_back(new EmptyState());
  current = states[0];
}

StateMachine::~StateMachine() {
  // for (IState* s : states)
  //   delete s;
}

void StateMachine::Change(StateName stateName, StateChangeParams params) {
  for (int i = 0; i < states.size(); i++) {
    if (states[i]->name == stateName) {
      current->Exit();
      current = states[i];
      current->Enter(params);
    }
  }
}

void StateMachine::Update(float dt) {
  current->Update(dt);
}

void StateMachine::Render() {
  current->Render();
}