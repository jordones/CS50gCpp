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
#include <iostream>
#include <stdlib.h>
#include <vector>

int WINDOW_WIDTH = 512;
int WINDOW_HEIGHT = 288;
StateMachine gStateMachine;

int main(void)
{
    srand(time(NULL));

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "raylib [core] example - basic window");
    SetTargetFPS(60);
    gStateMachine.PushState(new PlayState());
    gStateMachine.Change(Play, { 0 , false });
    // gStateMachine.Change(StateName::Empty, { 0, false});
    float spawnTimer = 0.0f;
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
    
    Bird bird;

    Texture2D tPipe = LoadTexture("../assets/pipe.png");
    std::vector<PipePair> pairs;
    int previousPipeYCoord = 0;

    bool scrolling = true;

    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------
        if (scrolling)
        {
          float dt = GetFrameTime();

          spawnTimer += dt;
          if (spawnTimer > 2.0f) {
            /*
            -- modify the last Y coordinate we placed so pipe gaps aren't too far apart
            -- no higher than 10 pixels below the top edge of the screen,
            -- and no lower than a gap length (90 pixels) from the bottom
            */
            int y = std::max<int>(
              -tPipe.height + 30,
              std::min(
                previousPipeYCoord + (rand() % 40 - 20), WINDOW_HEIGHT - 150 - tPipe.height
              )
            );
            previousPipeYCoord = y;
            pairs.push_back(PipePair(tPipe, y));

            spawnTimer = 0.0f;
          }

          bird.Update(dt);

          for (PipePair& p : pairs) {
            p.Update(dt);
            // Pause on Collision
            if (bird.Collides(p.pipes[Pipe::Top]) || bird.Collides(p.pipes[Pipe::Bottom])) {
              scrolling = false;
              gStateMachine.Change(Empty, { 0 , false });

            }
          }

          // Remove flagged pipes
          for (int i = 0; i < pairs.size(); i++)
          {
            if (pairs[i].remove)
            {
              pairs.erase(pairs.begin() + i);
            }
          }

          backgroundScrollOffset -= backgroundScrollSpeed * dt;
          if (backgroundScrollOffset < -backgroundLoopPoint) backgroundScrollOffset = 0;
          groundScrollOffset -= groundScrollSpeed * dt;
          groundScrollOffset = (int) groundScrollOffset % WINDOW_WIDTH;
          gStateMachine.Update(dt);
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        {
          BeginDrawing();
          {
            ClearBackground(RAYWHITE);
            DrawTextureV(background, (Vector2){ backgroundScrollOffset, 0 }, WHITE);
            for (PipePair& p : pairs)
              p.Render();
            DrawTextureV(ground, (Vector2){ groundScrollOffset, (float) WINDOW_HEIGHT - ground.height }, WHITE);
            bird.Render();
            DrawFPS(10, 10);
            gStateMachine.Render();
          }
          EndDrawing();
        }
    }

    UnloadTexture(background);        // Texture unloading
    UnloadTexture(ground);        // Texture unloading
    UnloadTexture(tPipe);        // Texture unloading

    CloseWindow();

    return 0;
}
