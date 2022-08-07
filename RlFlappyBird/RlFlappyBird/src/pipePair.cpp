#include "pipePair.h"

PipePair::PipePair(Texture2D texture, int y) {
  remove = false;
  xPos = GetScreenWidth();
  yPos = y;
  textureWidth = texture.width;
  pipes.push_back(Pipe(texture, y, Pipe::Top));
  pipes.push_back(Pipe(texture, y + texture.height + GAP_HEIGHT, Pipe::Bottom));
}

void PipePair::Update(float dt) {
  if (xPos > -textureWidth) {
    xPos = xPos - (Pipe::Speed * dt);
    pipes[Pipe::Top].xPos = xPos;
    pipes[Pipe::Bottom].xPos = xPos;
  } else {
    remove = true;
  }
}

void PipePair::Render() {
    pipes[Pipe::Top].Render();
    pipes[Pipe::Bottom].Render();
}