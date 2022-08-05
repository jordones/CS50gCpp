#include "bird.h"
#include <iostream>

Bird::Bird()
{
  image = LoadTexture("../assets/bird.png");
  width = image.width;
  height = image.height;
  position = { 
    GetScreenWidth() / 2 - (float) width / 2,
    GetScreenHeight() / 2 - (float) height / 2 
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