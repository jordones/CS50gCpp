#include "istate.h"

class PlayState : public IState {
  float timeElapsed = 0.0f;
  int seconds = 0;
public:
  PlayState();
  void Enter(StateChangeParams params) override;
  void Exit() override;
  void Update(float dt) override;
  void Render() override;
};
