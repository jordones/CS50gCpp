#pragma once

#include "raylib.h"
#include "pipe.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

class PipePair
{
protected:
  static const int GAP_HEIGHT = 90;

public:
  std::vector<Pipe> pipes;
  float xPos, yPos;
  int textureWidth;
  bool remove;
  bool scored;
  PipePair(Texture2D texture, int y);
  void Update(float dt);
  void Render();
};
