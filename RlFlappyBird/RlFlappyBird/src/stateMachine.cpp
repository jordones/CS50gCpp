#include "stateMachine.h"

StateMachine::StateMachine()
{
  // states.push_back(new EmptyState());
  // current = states[0];
  current = factory.CreateState(Empty, {0, false});
}

StateMachine::~StateMachine()
{
  // for (IState* s : states)
  //   delete s;
}

void StateMachine::PushState(IState *state)
{
  // states.push_back(state);
}

void StateMachine::Change(StateName stateName, StateChangeParams params)
{
  IState *newState = factory.CreateState(stateName, params);
  IState *oldState = current;

  oldState->Exit();
  delete oldState;
  // current->Exit();
  current = newState;
  current->Enter(params);
  // for (int i = 0; i < states.size(); i++)
  // {
  //   if (states[i]->name == stateName)
  //   {
  //     current->Exit();
  //     current = states[i];
  //     current->Enter(params);
  //   }
  // }
}

void StateMachine::Update(float dt)
{
  current->Update(dt);
}

void StateMachine::Render()
{
  current->Render();
}