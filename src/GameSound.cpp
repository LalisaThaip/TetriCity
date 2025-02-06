#include "GameSound.hpp"

#include <iostream>

#include "raylib-cpp.hpp"

GameSound::GameSound() { //constructor which defines volume and loads the sound to _sound datamember
  this->_soundVolume = 0.5;
  _sound = LoadSound("resources/sound.wav");
};

GameSound::GameSound(const char *soundLocation) { //constructor which defines and sets volume and loads the sound to _sound datamember
  this->_soundVolume = 0.5;
  _sound = LoadSound(soundLocation);
  SetSoundVolume(_sound, _soundVolume);
};

GameSound::GameSound(double volume, const char *soundLocation) { //constructor which defines and sets volume to argument volume and loads the sound to _sound datamember
  this->_soundVolume = volume;
  _sound = LoadSound(soundLocation);
  SetSoundVolume(_sound, _soundVolume);
};

GameSound::~GameSound() { //deconstruct and unloads sounds 
  CloseAudioDevice();
  UnloadSound(_sound);
}

void GameSound::Play() { PlaySound(this->_sound); }; //Plays Music 

void GameSound::Stop() { StopSound(this->_sound); }; //Stops playing Music
