#include <iostream>
#include "assetManager.h"

extern Font defaultFont;

AssetManager::~AssetManager()
{
  std::cout << "AssetManager Launched" << std::endl;
}

void AssetManager::LoadImpl()
{
  // Textures
  // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
  //----------------------------------------------------------------------------------
  textureMap["default"] = Texture2D{};
  textureMap["arrows"] = LoadTexture("../assets/graphics/arrows.png");
  textureMap["background"] = LoadTexture("../assets/graphics/background.png");
  textureMap["blocks"] = LoadTexture("../assets/graphics/blocks.png");
  textureMap["breakout"] = LoadTexture("../assets/graphics/breakout.png");
  textureMap["hearts"] = LoadTexture("../assets/graphics/hearts.png");
  textureMap["particle"] = LoadTexture("../assets/graphics/particle.png");
  textureMap["ui"] = LoadTexture("../assets/graphics/ui.png");

  // Fonts
  // NOTE: Fonts MUST be loaded after Window initialization
  //----------------------------------------------------------------------------------
  fontMap["default"] = LoadFont("../assets/fonts/font.ttf");
  defaultFont = fontMap.at("default");

  // Sounds
  // NOTE: Sounds MUST be loaded after AudioDevice initialization
  //----------------------------------------------------------------------------------
  soundMap["default"] = Sound{};
  soundMap["brick-hit-1"] = LoadSound("../assets/sounds/brick-hit-1.wav");
  soundMap["brick-hit-2"] = LoadSound("../assets/sounds/brick-hit-2.wav");
  soundMap["confirm"] = LoadSound("../assets/sounds/confirm.wav");
  soundMap["high_score"] = LoadSound("../assets/sounds/high_score.wav");
  soundMap["hurt"] = LoadSound("../assets/sounds/hurt.wav");
  soundMap["music"] = LoadSound("../assets/sounds/music.wav");
  soundMap["no-select"] = LoadSound("../assets/sounds/no-select.wav");
  soundMap["paddle_hit"] = LoadSound("../assets/sounds/paddle_hit.wav");
  soundMap["pause"] = LoadSound("../assets/sounds/pause.wav");
  soundMap["recover"] = LoadSound("../assets/sounds/recover.wav");
  soundMap["score"] = LoadSound("../assets/sounds/score.wav");
  soundMap["select"] = LoadSound("../assets/sounds/select.wav");
  soundMap["victory"] = LoadSound("../assets/sounds/victory.wav");
  soundMap["wall_hit"] = LoadSound("../assets/sounds/wall_hit.wav");
}

Texture2D AssetManager::GetTexture2DImpl(std::string key)
{
  if (textureMap.find(key) != textureMap.end())
  {
    return textureMap.at(key);
  }
  return textureMap.at("default");
}

Font AssetManager::GetFontImpl(std::string key)
{
  if (fontMap.find(key) != fontMap.end())
  {
    return fontMap.at(key);
  }
  return fontMap.at("default");
}

Sound AssetManager::GetSoundImpl(std::string key)
{
  if (soundMap.find(key) != soundMap.end())
  {
    return soundMap.at(key);
  }
  return soundMap.at("default");
}
