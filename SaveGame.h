#include "Requirements.h"
#ifndef SAVEGAME_H
#define SAVEGAME_H

class saveGame {
 private:
 protected:
 public:
  saveGame() {};

  void saveGames(int money, int crops, int upgrades) {
    ofstream saveFile("PlantSave.txt");
    if (saveFile.isOpen()) {
      saveFile << money << endl;
      saveFile << crops << endl;
      saveFile << upgrades << endl;
    }
  }

  ~saveGame() {};
};

#endif