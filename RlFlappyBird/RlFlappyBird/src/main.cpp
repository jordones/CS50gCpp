//
//  main.cpp
//  RlFlappyBird
//
//  Created by jordon on 2022-07-30.
//

#include "raylib.h"
#include "pipe.h"
#include "bird.h"
#include "pipePair.h"
#include "stateMachine.h"
#include "playState.h"
#include "titleScreenState.h"
#include "countdownState.h"
#include "scoreState.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

int WINDOW_WIDTH = 512;
int WINDOW_HEIGHT = 288;
StateMachine gStateMachine;
bool scrolling = true;

// Global Fonts
//----------------------------------------------------------------------------------
Font smallFont;
Font mediumFont;
Font flappyFont;
Font hugeFont;
//----------------------------------------------------------------------------------

// Global Sounds
//----------------------------------------------------------------------------------
Sound jumpSound;
Sound explosionSound;
Sound hurtSound;
Sound scoreSound;
Sound backgroundMusic;
//----------------------------------------------------------------------------------

int main(void)
{
  srand(time(NULL));

  InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "raylib [core] example - basic window");
  InitAudioDevice();
  SetTargetFPS(60);
  gStateMachine.PushState(new TitleScreenState());
  gStateMachine.PushState(new CountdownState());
  gStateMachine.PushState(new PlayState());
  gStateMachine.PushState(new ScoreState());
  gStateMachine.Change(TitleScreen, {0, false});

  // Textures
  // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
  //----------------------------------------------------------------------------------
  Texture2D background = LoadTexture("../assets/background.png");
  float backgroundScrollOffset = 0.0f;
  float backgroundScrollSpeed = 30.0f;
  int backgroundLoopPoint = 413;

  Texture2D ground = LoadTexture("../assets/ground.png");
  float groundScrollOffset = 0.0f;
  float groundScrollSpeed = 60.0f;

  smallFont = LoadFontEx("../assets/font.ttf", 8, NULL, 0);
  mediumFont = LoadFontEx("../assets/flappy.ttf", 14, NULL, 0);
  flappyFont = LoadFontEx("../assets/flappy.ttf", 28, NULL, 0);
  hugeFont = LoadFontEx("../assets/flappy.ttf", 56, NULL, 0);

  jumpSound = LoadSound("../assets/jump.wav");
  explosionSound = LoadSound("../assets/explosion.wav");
  hurtSound = LoadSound("../assets/hurt.wav");
  scoreSound = LoadSound("../assets/score.wav");
  backgroundMusic = LoadSound("../assets/marios_way.mp3");

  while (!WindowShouldClose())
  {
    // Update
    //----------------------------------------------------------------------------------
    if (!IsSoundPlaying(backgroundMusic))
    {
      PlaySound(backgroundMusic);
    }

    if (scrolling || gStateMachine.current->name != Play)
    {
      float dt = GetFrameTime();
      backgroundScrollOffset -= backgroundScrollSpeed * dt;
      if (backgroundScrollOffset < -backgroundLoopPoint)
        backgroundScrollOffset = 0;
      groundScrollOffset -= groundScrollSpeed * dt;
      groundScrollOffset = (int)groundScrollOffset % WINDOW_WIDTH;
      gStateMachine.Update(dt);
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    {
      BeginDrawing();
      {
        ClearBackground(RAYWHITE);
        DrawTextureV(background, (Vector2){backgroundScrollOffset, 0}, WHITE);
        gStateMachine.Render();
        DrawTextureV(ground, (Vector2){groundScrollOffset, (float)WINDOW_HEIGHT - ground.height}, WHITE);
        DrawFPS(10, 10);
      }
      EndDrawing();
    }
  }

  UnloadTexture(background); // Texture unloading
  UnloadTexture(ground);     // Texture unloading
  UnloadSound(jumpSound);
  UnloadSound(explosionSound);
  UnloadSound(hurtSound);
  UnloadSound(scoreSound);
  UnloadSound(backgroundMusic);
  CloseWindow();

  return 0;
}
