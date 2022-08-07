//
//  pipe.h
//  RlFlappyBird
//
//  Created by jordon on 2022-07-30.
//

#pragma once

#include "raylib.h"
#include <iostream>
#include <stdlib.h>

class Pipe {
public:
  enum Side {
    Top = 0, Bottom = 1
  };

  float xPos, yPos;
  int width;
  Side side;
private:
  Texture2D image;
public:
  Pipe(Texture2D image, int y, Side position);
  void Update(float dt);
  void Render();
};
