#pragma once

#include "raylib-cpp.hpp"

class GameSound {
 private:
  double _soundVolume;
  Sound _sound;

 public:
  GameSound();
  GameSound(const char *);
  GameSound(double, const char *);

  void Play();
  void Stop();
  ~GameSound();
};
