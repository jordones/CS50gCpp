//
//  pipe.cpp
//  RlFlappyBird
//
//  Created by jordon on 2022-07-30.
//

#include "pipe.h"

float pipeScrollSpeed = -60.0f;

Pipe::Pipe(Texture2D texture, int y, Side position) {
    // yPos = -rand() % (GetScreenHeight() / 4) + (GetScreenHeight() - 60);
    yPos = y;
    image = texture;
    width = texture.width;
    xPos = GetScreenWidth() + width;
    side = position;
}

void Pipe::Update(float dt) {
  xPos += pipeScrollSpeed * dt;
}

void Pipe::Render() {
  DrawTexture(image, xPos, yPos, WHITE);
}
