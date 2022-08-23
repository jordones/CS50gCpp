#pragma once
#include "istate.h"
#include "bird.h"
#include "pipePair.h"

class TitleScreenState : public IState
{
protected:
  Bird bird;
  Texture2D tPipe;
  std::vector<PipePair> pairs;
  int previousPipeYCoord;
  float spawnTimer;

public:
  TitleScreenState();
  ~TitleScreenState();
  void Enter(StateChangeParams params) override;
  void Exit() override;
  void Update(float dt) override;
  void Render() override;
};
