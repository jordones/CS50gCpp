//
//  pipe.cpp
//  RlFlappyBird
//
//  Created by jordon on 2022-07-30.
//

#include "pipe.h"

float pipeScrollSpeed = -60.0f;

Pipe::Pipe(Texture2D texture) {
    xPos = 10;
    yPos = -rand() % (GetScreenHeight() / 4) + (GetScreenHeight() - 10);
    image = texture;
    width = texture.width;
}

void Pipe::Update(float dt) {
  xPos -= pipeScrollSpeed * dt;
}

void Pipe::Render() {
  DrawTexture(image, xPos, yPos, WHITE);
}
