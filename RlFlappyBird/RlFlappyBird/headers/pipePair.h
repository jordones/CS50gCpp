#pragma once

#include "raylib.h"
#include "pipe.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

class PipePair {
protected:
  static const int GAP_HEIGHT = 90;
private:
  int xPos, yPos;
  std::vector<Pipe> pipes;
public:
  bool remove;
  PipePair(Texture2D texture, int y);
  void Update(float dt);
  void Render();
};
