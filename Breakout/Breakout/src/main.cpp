//
//  main.cpp
//  breakout
//
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "raylib.h"
#include "constants.h"
#include "assetManager.h"

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;
extern StateMachine gStateMachine;

int main(void)
{
  srand(time(NULL));

  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "raylib [core] example - basic window");
  InitAudioDevice();
  SetMasterVolume(0.05f);
  SetTargetFPS(60);
  AssetManager::Load();
  gStateMachine.Change(TitleScreen, {0, false});

  PlaySound(AssetManager::GetSound("music"));
  while (!WindowShouldClose())
  {
    // Update
    //----------------------------------------------------------------------------------
    {
      float dt = GetFrameTime();
      gStateMachine.Update(dt);
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    {
      BeginDrawing();
      {
        ClearBackground(RAYWHITE);
        gStateMachine.Render();
        DrawFPS(10, 10);
      }
      EndDrawing();
    }
  }
  CloseAudioDevice();
  CloseWindow();

  return 0;
}
