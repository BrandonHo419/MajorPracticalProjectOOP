#include "Requirements.h"
#ifndef AUDIO_H
#define AUDIO_H


class Audio {
    private:
    SoundBuffer soundtrack1;
    SoundBuffer soundtrack2;
    Sound playSound1;
    Sound playSound2;
    Clock c;

    //

    bool isTrue;

    //

    SoundBuffer moneySound;
    Sound playMoneySounds;
    
    protected:

    public:
    void playSounds() {
        isTrue = false;
        soundtrack1.loadFromFile("piano1.wav");
        soundtrack2.loadFromFile("eesound.wav");
        playSound1.setBuffer(soundtrack1);
        playSound2.setBuffer(soundtrack2);
        playSound1.play();
        c.restart();
        isTrue = true;
        if(isTrue == true) {
            if(c.getElapsedTime().asSeconds() >= 244) {
                playSound1.stop();
                playSound2.play();
                isTrue = false;
            }
        }    
    }

    void playMoneySound() {
        moneySound.loadFromFile("moneySound.wav");
        playMoneySounds.setBuffer(moneySound);
        playMoneySounds.play();
    }

};

#endif