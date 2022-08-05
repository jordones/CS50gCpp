//
//  main.cpp
//  RlFlappyBird
//
//  Created by jordon on 2022-07-30.
//

#include "raylib.h"
#include "pipe.hpp"
#include "bird.h"
#include <iostream>

int WINDOW_WIDTH = 512;
int WINDOW_HEIGHT = 288;

int main(void)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "raylib [core] example - basic window");
    SetTargetFPS(60);

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
    // Texture2D bird = LoadTexture("../assets/bird.png");        // Texture loading
    Bird bird;

    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------
        float dt = GetFrameTime();
        {
          backgroundScrollOffset -= backgroundScrollSpeed * dt;
          if (backgroundScrollOffset < -backgroundLoopPoint) backgroundScrollOffset = 0;
          groundScrollOffset -= groundScrollSpeed * dt;
          groundScrollOffset = (int) groundScrollOffset % WINDOW_WIDTH;
          bird.Update(dt);
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        {
          BeginDrawing();
          {
            ClearBackground(RAYWHITE);
            DrawTextureV(background, (Vector2){ backgroundScrollOffset, 0 }, WHITE);
            DrawTextureV(ground, (Vector2){ groundScrollOffset, (float) WINDOW_HEIGHT - ground.height }, WHITE);
            bird.Render();
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            DrawFPS(10, 10);
          }
          EndDrawing();
        }
    }

    UnloadTexture(background);        // Texture unloading
    UnloadTexture(ground);        // Texture unloading
    CloseWindow();

    return 0;
}
