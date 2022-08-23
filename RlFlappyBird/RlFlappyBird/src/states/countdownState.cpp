#include "countdownState.h"
#include "stateMachine.h"

extern StateMachine gStateMachine;
extern Font mediumFont;
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
  DrawTextEx(mediumFont, "CountdownState", {20, 30}, 14.0f, 1.0f, BLACK);
  Vector2 textSize = MeasureTextEx(mediumFont, &countString, 14.0f, 1.0f);
  DrawTextEx(mediumFont, &countString, {(float)WINDOW_WIDTH / 2 - textSize.x / 2, (float)WINDOW_HEIGHT / 2 - textSize.y / 2}, 14.0f, 1.0f, BLACK);
}
