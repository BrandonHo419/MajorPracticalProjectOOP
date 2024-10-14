#include "Requirements.h"
#ifndef AUDIO_H
#define AUDIO_H

class Audio {
 private:
  SoundBuffer soundtrack1;
  SoundBuffer soundtrack2;
  SoundBuffer soundtrack3;
  SoundBuffer soundtrack4;
  SoundBuffer soundtrack5;
  Sound playSound1;
  Sound playSound2;
  Sound playSound3;
  Sound playSound4;
  Sound playSound5;
  Clock c;

  enum class SoundState { NONE, FIRST, SECOND, THIRD, FOURTH, FIFTH };
  SoundState currentState;
  //

  bool isTrue;

  //

  SoundBuffer moneySound;
  Sound playMoneySounds;

 protected:
 public:
  Audio() : currentState(SoundState::NONE) {
    soundtrack1.loadFromFile("wawg.wav");
    soundtrack3.loadFromFile("weeeee.wav");
    soundtrack2.loadFromFile("gow.wav");
    soundtrack4.loadFromFile("ascendant.wav");
    soundtrack5.loadFromFile("intense.wav");
    playSound1.setBuffer(soundtrack1);
    playSound2.setBuffer(soundtrack2);
    playSound3.setBuffer(soundtrack3);
    playSound4.setBuffer(soundtrack4);
    playSound5.setBuffer(soundtrack5);

    playSound1.setVolume(70);
    playSound2.setVolume(70);
    playSound3.setVolume(70);
    playSound4.setVolume(40);
    playSound5.setVolume(45);
  };

  void playSounds() {
    if (currentState == SoundState::NONE) {
      playSound1.play();
      currentState = SoundState::FIRST;
    } else if (currentState == SoundState::FIRST &&
               playSound1.getStatus() == Sound::Stopped) {
      cout << "Playing next song" << endl;
      playSound2.play();
      currentState = SoundState::SECOND;  // Update state to SECOND
    } else if (currentState == SoundState::SECOND &&
               playSound2.getStatus() == Sound::Stopped) {
      cout << "Playing third song" << endl;
      playSound3.play();
      currentState = SoundState::THIRD;  // Update state to THIRD
    }
  }

  void playMoneySound() {
    moneySound.loadFromFile("moneySound.wav");
    playMoneySounds.setBuffer(moneySound);
    playMoneySounds.play();
  }
};

#endif