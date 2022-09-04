//
//  main.cpp
//  RlFlappyBird
//
//  Created by jordon on 2022-07-30.
//
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "raylib.h"
#include "state/stateMachine.h"

int WINDOW_WIDTH = 512;
int WINDOW_HEIGHT = 288;
StateMachine gStateMachine;

// Global Fonts
//----------------------------------------------------------------------------------
Font defaultFont;
//----------------------------------------------------------------------------------

// Global Sounds
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

int main(void)
{
  srand(time(NULL));

  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "raylib [core] example - basic window");
  InitAudioDevice();
  SetMasterVolume(0.05f);
  SetTargetFPS(60);
  gStateMachine.Change(TitleScreen, {0, false});

  // Textures
  // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
  //----------------------------------------------------------------------------------

  // Fonts
  // NOTE: Fonts MUST be loaded after Window initialization
  //----------------------------------------------------------------------------------
  defaultFont = GetFontDefault();

  // Sounds
  // NOTE: Sounds MUST be loaded after AudioDevice initialization
  //----------------------------------------------------------------------------------

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
