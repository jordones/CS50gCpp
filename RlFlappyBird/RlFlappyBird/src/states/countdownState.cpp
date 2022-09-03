#include "countdownState.h"
#include "stateMachine.h"

extern StateMachine gStateMachine;
extern Font flappyFont;
extern int WINDOW_HEIGHT;
extern int WINDOW_WIDTH;

CountdownState::CountdownState()
{
  name = Countdown;
}

CountdownState::~CountdownState()
{
}

void CountdownState::Enter(StateChangeParams params)
{
  std::cout << "Entered CountdownState" << std::endl;
}

void CountdownState::Exit()
{
  std::cout << "Exited CountdownState" << std::endl;
}

void CountdownState::Update(float dt)
{
  timeElapsed += dt;
  if (timeElapsed > 1.0f)
  {
    secondsElapsed++;
    countString--;
    timeElapsed = 0;
  }
  if (secondsElapsed >= 3)
  {
    gStateMachine.Change(Play, {0, false});
  }
}

void CountdownState::Render()
{
  DrawTextEx(flappyFont, "CountdownState", {20, 30}, 28.0f, 1.0f, BLACK);
  Vector2 textSize = MeasureTextEx(flappyFont, &countString, 28.0f, 1.0f);
  DrawTextEx(flappyFont, &countString, {(float)WINDOW_WIDTH / 2 - textSize.x / 2, (float)WINDOW_HEIGHT / 2 - textSize.y / 2}, 28.0f, 1.0f, BLACK);
}
