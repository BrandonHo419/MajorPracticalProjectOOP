
#include "Requirements.h"
#include "Shop.h"
#include "Strawberries.h"
#include "Weather.h"
#ifndef RANDOMEVENTS_H
#define RANDOMEVENTS_H

class RandomEvents : public Shop, public Weather {
 private:
  Clock c;
  int min;
  int max;
  random_device rd;

  Font font;

  float adjustRain(float rain) {
    this->rainfall = rain;
    return rain;
  }

  bool eventOne = false;
  bool eventTwo = false;
  bool eventThree = false;
  bool eventFour = false;

 protected:
 public:
  bool getEvent1() { return eventOne; }

  bool getEvent2() { return eventTwo; }

  bool getEvent3() { return eventThree; }

  bool getEvent4() { return eventFour; }

  Text message1;

  RandomEvents() : c(), min(1), max(4), rd() {}

  void genRand() {
    message1.setFillColor(Color::White);
    message1.setFont(font);
    message1.setCharacterSize(21);
    mt19937 getRand(rd());
    uniform_int_distribution<> distrib(min, max);
    int genVal = distrib(getRand);
    cout << genVal << endl;
    if (genVal == 1) {
      heatStroke();
    } else if (genVal == 2) {
      greatThings();
    } else if (genVal == 3) {
      cropPriceForce();
    } else if (genVal == 4) {
      economicDepression();
    }
  }

  void checkRand() {
    cout << "Checking for events" << endl;
    if (c.getElapsedTime().asSeconds() >= 15) {
      genRand();
      c.restart();
      cout << "Generating Event" << endl;
    }
  };

  Font getFont() {
    font.loadFromFile("Arial.ttf");
    return font;
  }
  float heatStroke() {
    eventOne = true;
    getFont();
    message1.setString(
        "A heatstroke happened and your plants are growing super duper slow!");
    temperature = 70;
    rainfall = 0;
    adjustRain(rainfall);

    return temperature;
  };

  float greatThings() {
    eventTwo = true;
    getFont();
    message1.setString(
        "A major economic boom has happened. Take advantage of this and sell "
        "your crops for 2x the price! (lasts 5 minutes)");
    c.restart();
    priceModifier = 2.0f;

    if (c.getElapsedTime().asSeconds() >= 300) {
      priceModifier = 1.0f;
    } else {
      c.getElapsedTime().asSeconds();
    }
    return priceModifier;
  }

  float cropPriceForce() {
    eventThree = true;
    getFont();
    message1.setString("Strawberry pricing is weird Sell them for 1000.");
    priceModifier = 2.0f;

    return priceModifier;
  }

  float economicDepression() {
    eventFour = true;
    getFont();
    message1.setString(
        "Unfortunately due to the government printing too much money. The "
        "country is in depression and your crops sell for 0.5x price");
    priceModifier = 0.5f;
    if (c.getElapsedTime().asSeconds() >= 300) {
      priceModifier = 1.0f;
    } else {
      c.getElapsedTime().asSeconds();
    }
    return priceModifier;
  }
};

#endif