//
//  pipe.cpp
//  RlFlappyBird
//
//  Created by jordon on 2022-07-30.
//

#include "pipe.h"

Pipe::Pipe(float x, float y, Texture2D texture) {
    xPos = x;
    yPos = y;
    image = texture;
}

void Pipe::Render() {
  DrawTexture(image, xPos, yPos, WHITE);
}
