#include "state/stateFactory.h"
#include "state/states/playState.h"
#include "state/states/titleScreenState.h"

IState *StateFactory::CreateState(StateName stateName)
{
  switch (stateName)
  {
  case Play:
    return new PlayState();
  case TitleScreen:
    return new TitleScreenState();
  case Empty:
  default:
    return new EmptyState();
  }
}