#include "playState.h"
#include "pipe.h"
#include "stateMachine.h"
#include <string>

extern StateMachine gStateMachine;
extern bool scrolling;
extern int WINDOW_HEIGHT;
extern int WINDOW_WIDTH;
extern Font mediumFont;

PlayState::PlayState()
{
  name = Play;
  tPipe = LoadTexture("../assets/pipe.png");
  int previousPipeYCoord = 0;
  float spawnTimer = 0.0f;
}

PlayState::~PlayState()
{
  UnloadTexture(tPipe); // Texture unloading
}

void PlayState::Enter(StateChangeParams params)
{
  std::cout << "Entered PlayState" << std::endl;
}

void PlayState::Exit()
{
  std::cout << "Exited PlayState" << std::endl;
}

void PlayState::Update(float dt)
{
  spawnTimer += dt;
  if (spawnTimer > 2.0f)
  {
    /*
    -- modify the last Y coordinate we placed so pipe gaps aren't too far apart
    -- no higher than 10 pixels below the top edge of the screen,
    -- and no lower than a gap length (90 pixels) from the bottom
    */
    int y = std::max<int>(
        -tPipe.height + 30,
        std::min(
            previousPipeYCoord + (rand() % 40 - 20), WINDOW_HEIGHT - 150 - tPipe.height));
    previousPipeYCoord = y;
    pairs.push_back(PipePair(tPipe, y));

    spawnTimer = 0.0f;
  }

  bird.Update(dt);

  for (PipePair &p : pairs)
  {
    p.Update(dt);

    // Check if the pipe was scored
    if (!p.scored)
    {
      if (p.xPos + p.textureWidth < bird.position.x)
      {
        score++;
        std::cout << "Score: " << score << std::endl;
        p.scored = true;
      }
    }

    // Pause on Collision
    if (bird.Collides(p.pipes[Pipe::Top]) || bird.Collides(p.pipes[Pipe::Bottom]))
    {
      scrolling = false;
      gStateMachine.Change(Score, {0, false});
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
}

void PlayState::Render()
{
  DrawTextEx(mediumFont, "PlayState", {20, 30}, 14.0f, 1.0f, BLACK);
  std::string scoreOutput = "Score: " + std::to_string(score);
  DrawTextEx(mediumFont, scoreOutput.c_str(), {20, 50}, 14.0f, 1.0f, BLACK);

  for (PipePair &p : pairs)
    p.Render();
  bird.Render();
}
