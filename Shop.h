#ifndef SHOP_H
#define SHOP_H

#include <SFML/Graphics.hpp>
#include <string>

#include "Player.h"

class Shop {
 public:
  Shop();
  void purchaseFertiliser(Player& player);  // Purchase Fertiliser
  void purchaseGreenhouse(Player& player);  // Purchase Greenhouse
  std::string getItemVarStr(
      const std::string& itemName,
      const std::string& variable);  // Retrieve item price as a string
  float getItemPrice(const std::string& itemName);  // Retrieve item price
  int getCropVar(const std::string& cropName,
                 const std::string& variable);  // Retrieve crop variable
  std::string getCropVarStr(
      const std::string& cropName,
      const std::string& variable);  // Retrieve crop var as a string
  void afterPurchaseCrop(
      const std::string&
          cropName);  // After purchasing a crop, increase price to values
  void weatherAffected(float temperature,
                       float rainfall);  // Apply the weather variables
  float getWeatherModfiers(
      const std::string& cropName);  // Retrieve rainfall modifier
  std::string getWeatherModfiersStr(
      const std::string& cropName);  // Retrieve crop var as a string
 private:
  float sellPercentage = 0.4f;
  const float increasePricePercentage = 1.20f;
  float temporaryTemperatureModifier = 1.0f;
  float temporaryRainfallModifier = 1.0f;
  // Crop and Item Variables using maps
  std::map<std::string, float> cropPrices;
  std::map<std::string, float> cropGrowthTime;
  std::map<std::string, float> cropSellValue;
  std::map<std::string, float> itemPrices;
  std::map<std::string, float> itemModifier;
  std::map<std::string, float> weatherModifier;

 protected:
  float priceModifier = 1.0f;
};
#endif