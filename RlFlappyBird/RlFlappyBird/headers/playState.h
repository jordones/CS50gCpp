#pragma once
#include "istate.h"
#include "bird.h"
#include "pipePair.h"

class PlayState : public IState
{
protected:
  Bird bird;
  Texture2D tPipe;
  std::vector<PipePair> pairs;
  int previousPipeYCoord;
  float spawnTimer;
  int score;

public:
  PlayState();
  ~PlayState();
  void Enter(StateChangeParams params) override;
  void Exit() override;
  void Update(float dt) override;
  void Render() override;
};
