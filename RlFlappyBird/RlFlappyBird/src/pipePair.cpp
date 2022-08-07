#include "pipePair.h"

PipePair::PipePair(Texture2D texture, int y) {
  remove = false;
  xPos = GetScreenWidth() + 32;
  yPos = y;
  pipes.push_back(Pipe(texture, y, Pipe::Top));
  pipes.push_back(Pipe(texture, y + texture.height + GAP_HEIGHT, Pipe::Bottom));
}

void PipePair::Update(float dt) {
  for (Pipe& p : pipes)
    p.Update(dt);
}

void PipePair::Render() {
  for (Pipe& p : pipes)
    p.Render();
}