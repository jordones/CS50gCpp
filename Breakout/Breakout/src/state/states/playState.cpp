#include "state/stateMachine.h"
#include "state/states/playState.h"

#include <string>

extern StateMachine gStateMachine;
extern int WINDOW_HEIGHT;
extern int WINDOW_WIDTH;
extern Font defaultFont;

PlayState::PlayState()
{
  name = Play;
}

PlayState::~PlayState()
{
}

void PlayState::Enter(StateChangeParams params)
{
  std::cout << "Entered PlayState" << std::endl;
}

void PlayState::Exit()
{
  std::cout << "Exited PlayState" << std::endl;
}

void PlayState::Update(float dt)
{
}

void PlayState::Render()
{
  // DrawTextEx(defaultFont, "PlayState", {20, 30}, 14.0f, 1.0f, BLACK);
}
