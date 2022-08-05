//
//  pipe.h
//  RlFlappyBird
//
//  Created by jordon on 2022-07-30.
//

#pragma once

#include "raylib.h"
#include <iostream>

class Pipe {
public:
  float xPos, yPos;
private:
  Texture2D image;
public:
  Pipe(float x, float y, Texture2D image);
  void Render();
};
