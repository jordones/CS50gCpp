#include "bird.h"
#include <iostream>

extern int WINDOW_HEIGHT;
extern int WINDOW_WIDTH;
extern Sound jumpSound;
Bird::Bird()
{
  image = LoadTexture("../assets/bird.png");
  width = image.width;
  height = image.height;
  position = {
      WINDOW_WIDTH / 2 - (float)width / 2,
      WINDOW_HEIGHT / 2 - (float)height / 2};
  velocity = {0, 0};
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
    PlaySound(jumpSound);
    velocity.y = UPWARD_FORCE;
  }

  position.y += velocity.y;
}

// AABB collision check
bool Bird::Collides(Pipe p)
{
  int leftTopOffset = 4;
  int rightBottomOffset = 4;

  bool leftCollision = (position.x + leftTopOffset) + (width - rightBottomOffset) >= p.xPos;
  bool rightCollision = (position.x + leftTopOffset) <= p.xPos + p.width;
  bool bottomCollision = position.y + height - rightBottomOffset >= p.yPos;
  bool topCollision = position.y + leftTopOffset <= p.yPos + p.height;
  if (leftCollision && rightCollision)
    if (bottomCollision && topCollision)
      return true;
  return false;
}