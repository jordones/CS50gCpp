#include "stateFactory.h"
#include "playState.h"
#include "scoreState.h"
#include "titleScreenState.h"
#include "countdownState.h"

IState *StateFactory::CreateState(StateName stateName, StateChangeParams params)
{
  switch (stateName)
  {

  case Play:
    return new PlayState();
  case TitleScreen:
    return new TitleScreenState();
  case Countdown:
    return new CountdownState();
  case Score:
    return new ScoreState();
  case Empty:
  default:
    return new EmptyState();
  }
}