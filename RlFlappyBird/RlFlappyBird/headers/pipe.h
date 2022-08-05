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
  float xPos, yPos;
  int width;
private:
  Texture2D image;
public:
  Pipe(Texture2D image);
  void Update(float dt);
  void Render();
};
