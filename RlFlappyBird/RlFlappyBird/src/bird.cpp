#include "bird.h"
#include <iostream>

extern int WINDOW_HEIGHT;
extern int WINDOW_WIDTH;

Bird::Bird()
{
  image = LoadTexture("../assets/bird.png");
  width = image.width;
  height = image.height;
  position = { 
    WINDOW_WIDTH / 2 - (float) width / 2,
    WINDOW_HEIGHT / 2 - (float) height / 2 
  };
  velocity = { 0, 0 };
}

void Bird::Render()
{
  DrawTextureV(image, position, WHITE);
}


void Bird::Update(float dt)
{
  velocity.y += GRAVITY * dt;

  if (IsKeyPressed(KEY_SPACE)) 
  {
    velocity.y = UPWARD_FORCE;
  }

  position.y += velocity.y;
}