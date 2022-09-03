#include "scoreState.h"
#include "stateMachine.h"
#include <string>

extern StateMachine gStateMachine;
extern Font flappyFont;
extern Font mediumFont;
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
  score = params.score;
}

void ScoreState::Exit()
{
  std::cout << "Exited ScoreState" << std::endl;
}

void ScoreState::Update(float dt)
{
  if (IsKeyPressed(KEY_P))
  {
    std::cout << "Countdown" << std::endl;
    gStateMachine.Change(Countdown, {0, false});
  }
}

void ScoreState::Render()
{
  std::string scoreOutput = "Score: " + std::to_string(score);
  DrawTextEx(mediumFont, scoreOutput.c_str(), {20, 50}, 14.0f, 1.0f, BLACK);

  DrawTextEx(mediumFont, "ScoreState", {20, 30}, 14.0f, 1.0f, BLACK);
  Vector2 textSize = MeasureTextEx(flappyFont, "Press [P] to play again", 14.0f, 1.0f);
  DrawTextEx(flappyFont, "Press [P] to play again", {(float)WINDOW_WIDTH / 2 - textSize.x / 2, (float)WINDOW_HEIGHT / 2 - textSize.y / 2}, 14.0f, 1.0f, BLACK);
}
