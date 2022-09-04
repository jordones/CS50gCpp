#include "state/stateFactory.h"
#include "state/states/playState.h"
#include "state/states/scoreState.h"
#include "state/states/titleScreenState.h"
#include "state/states/countdownState.h"

IState *StateFactory::CreateState(StateName stateName)
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