#pragma once
#include "raylib.h"
#include <unordered_map>

class AssetManager
{
public:
  AssetManager(const AssetManager &) = delete;
  static AssetManager &Get()
  {
    static AssetManager instance;
    return instance;
  }
  static void Load() { Get().LoadImpl(); };
  static Sound GetSound(std::string key) { return Get().GetSoundImpl(key); };
  static Font GetFont(std::string key) { return Get().GetFontImpl(key); };
  static Texture2D GetTexture2D(std::string key) { return Get().GetTexture2DImpl(key); };

protected:
  std::unordered_map<std::string, Sound> soundMap;
  std::unordered_map<std::string, Font> fontMap;
  std::unordered_map<std::string, Texture2D> textureMap;
  ~AssetManager();

private:
  AssetManager(){};
  void LoadImpl();
  Sound GetSoundImpl(std::string key);
  Font GetFontImpl(std::string key);
  Texture2D GetTexture2DImpl(std::string key);
};
