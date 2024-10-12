#include "Crop.h"
#include "Requirements.h"
#include "Shop.h"
#include "Strawberries.h"
#include "loadRect.h"
#ifndef RANDOMEVENTS_H
#define RANDOMEVENTS_H

class RandomEvents : public Shop, public Crop {
 private:
  Clock c;
  int min;
  int max;
  random_device rd;

  Font font;

  virtual void Draw(sf::RenderTarget& rt) override {}
  virtual void Update(float dt, float waitTime, bool resetFrame,
                      Player& player) override {}
  float virtual getGrowthTime() override { return 0; }
  void virtual setGrowthTime(float modifier) override {}

 protected:
 public:
  bool eventOne = false;
  bool eventTwo = false;
  bool eventThree = false;
  bool eventFour = false;
  bool eventFive = false;

  Text message1;

  RandomEvents() : c(), min(1), max(5), rd() {}

  void genRand() {
    message1.setFillColor(Color::White);
    message1.setFont(font);
    message1.setCharacterSize(21);
    mt19937 getRand(rd());
    uniform_int_distribution<> distrib(min, max);
    int genVal = distrib(getRand);
    cout << genVal << endl;
    if (genVal == 1) {
      deadFarmer();
    } else if (genVal == 2) {
      greatThings();
    }
  }

  void checkRand() {
    if (c.getElapsedTime().asSeconds() >= 120) {
      genRand();
      c.restart();
    }
  };

  Font getFont() {
    font.loadFromFile("Arial.ttf");
    return font;
  }
  float deadFarmer() {
    eventOne = true;
    getFont();
    message1.setString(
        "A rival competitor hired Agent 47 and he BRUTALLY assasinated all "
        "of "
        "your farmers and stole some money");

    haveWorkers = false;
    numOfWorkers = 0;
    workersLevel = 0;
    money = money - 520;

    return money;
  };

  void greatThings() {
    eventTwo = true;
    getFont();
    message1.setString(
        "A major economic boom has happened. Take advantage of this and sell "
        "your crops for 2x the price! (lasts 5 minutes)");
    c.restart();
    globalModifier = 2;

    if (c.getElapsedTime().asSeconds() >= 300) {
      globalModifier = 1;
    } else {
      c.getElapsedTime().asSeconds();
    }
  }
};

#endif