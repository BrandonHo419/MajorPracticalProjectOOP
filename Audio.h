#include "Requirements.h"
#ifndef AUDIO_H
#define AUDIO_H

class Audio {
private:
    Music music; // Use music for playing a song

public:
    Audio();
    void playSoundtrack(); // Play the song
    void stopSoundtrack(); // Stop the song
};

#endif