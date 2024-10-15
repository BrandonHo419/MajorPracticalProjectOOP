#include "Audio.h"

Audio::Audio() {
    // Load the soundtrack
    if (!music.openFromFile("gow.ogg")) {
        std::cerr << "Error loading soundtrack" << std::endl;
    }
    music.setVolume(40); // Set volume for the soundtrack
}

void Audio::playSoundtrack() {
    if (music.getStatus() != Sound::Playing) {
        music.play(); // Play the soundtrack if it's not already playing
    }
}

void Audio::stopSoundtrack() {
    music.stop(); // Stop the soundtrack
}