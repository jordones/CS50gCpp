#include "playState.h"

PlayState::PlayState() {
  name = Play;
}

void PlayState::Enter(StateChangeParams params) {
  std::cout << "Entered PlayState" << std::endl;
}

void PlayState::Exit() {
  std::cout << "Exited PlayState" << std::endl;
}

void PlayState::Update(float dt) {
  timeElapsed += dt;
  if (timeElapsed > 1) {
    seconds++;
    timeElapsed = 0.0f;
    std::cout << "PlayState Seconds: " << seconds << std::endl;
  } 
}

void PlayState::Render() {
  DrawText("PlayState", 20, 30, 16, BLACK);
}

