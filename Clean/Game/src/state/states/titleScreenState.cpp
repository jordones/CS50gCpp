#include "state/states/titleScreenState.h"
#include "state/stateMachine.h"

extern StateMachine gStateMachine;
extern Font defaultFont;
extern int WINDOW_HEIGHT;
extern int WINDOW_WIDTH;

TitleScreenState::TitleScreenState()
{
  name = TitleScreen;
}

TitleScreenState::~TitleScreenState()
{
}

void TitleScreenState::Enter(StateChangeParams params)
{
  std::cout << "Entered TitleScreenState" << std::endl;
}

void TitleScreenState::Exit()
{
  std::cout << "Exited TitleScreenState" << std::endl;
}

void TitleScreenState::Update(float dt)
{
  if (IsKeyPressed(KEY_SPACE))
  {
    gStateMachine.Change(Play, {0, false});
  }
}

void TitleScreenState::Render()
{
  DrawTextEx(defaultFont, "TitleScreenState", {20, 30}, 14.0f, 1.0f, BLACK);
  Vector2 textSize = MeasureTextEx(defaultFont, "Press [SpaceBar] to start", 14.0f, 1.0f);
  DrawTextEx(defaultFont, "Press [SpaceBar] to start", {(float)WINDOW_WIDTH / 2 - textSize.x / 2, (float)WINDOW_HEIGHT / 2 - textSize.y / 2}, 14.0f, 1.0f, BLACK);
}
