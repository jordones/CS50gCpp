#pragma once

#include "state/states/istate.h"
#include <vector>

class StateFactory
{
public:
  IState *CreateState(StateName stateName);
};
