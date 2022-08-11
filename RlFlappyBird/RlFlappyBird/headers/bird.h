#pragma once
#include "raylib.h"
#include "pipe.h"

class Bird
{
private:
  Texture2D image;

public:
  static const int GRAVITY = 20;
  static const int UPWARD_FORCE = -5;
  int width;
  int height;
  Vector2 position;
  Vector2 velocity;

  Bird();
  void Render();
  void Update(float dt);
  bool Collides(Pipe p);
  ~Bird()
  {
    UnloadTexture(image);
  }
};
