#pragma once

#include "istate.h"
#include <vector>

class StateFactory
{
public:
  IState *CreateState(StateName stateName);
};
