#include "stateMachine.h"

StateMachine::StateMachine()
{
  current = factory.CreateState(Empty);
}

StateMachine::~StateMachine()
{
}

void StateMachine::Change(StateName stateName, StateChangeParams params)
{
  IState *newState = factory.CreateState(stateName);
  IState *oldState = current;

  oldState->Exit();
  delete oldState;
  current = newState;
  current->Enter(params);
}

void StateMachine::Update(float dt)
{
  current->Update(dt);
}

void StateMachine::Render()
{
  current->Render();
}