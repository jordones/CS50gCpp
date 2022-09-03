#include "scoreState.h"
#include "stateMachine.h"

extern StateMachine gStateMachine;
extern Font flappyFont;
extern int WINDOW_HEIGHT;
extern int WINDOW_WIDTH;

ScoreState::ScoreState()
{
  name = Score;
}

ScoreState::~ScoreState()
{
}

void ScoreState::Enter(StateChangeParams params)
{
  std::cout << "Entered ScoreState" << std::endl;
}

void ScoreState::Exit()
{
  std::cout << "Exited ScoreState" << std::endl;
}

void ScoreState::Update(float dt)
{
}

void ScoreState::Render()
{
  DrawTextEx(flappyFont, "ScoreState", {20, 30}, 28.0f, 1.0f, BLACK);
}
