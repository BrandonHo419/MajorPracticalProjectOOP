#include "Shop.h"

#include <iomanip>
#include <iostream>
#include <sstream>

Shop::Shop() {
  // Initialize crop prices, growth time and sell value
  cropPrices["Strawberries"] = 10.0f;
  cropPrices["Blueberries"] = 150.0f;
  cropPrices["Carrots"] = 650.0f;
  cropPrices["Beets"] = 3000.0f;
  cropPrices["Tomatoes"] = 10000.0f;
  cropGrowthTime["Strawberries"] = 2.0f;
  cropGrowthTime["Blueberries"] = 4.0f;
  cropGrowthTime["Carrots"] = 6.0f;
  cropGrowthTime["Beets"] = 8.0f;
  cropGrowthTime["Tomatoes"] = 10.0f;
  cropSellValue["Strawberries"] =
      cropPrices["Strawberries"] * sellPercentage * priceModifier;
  cropSellValue["Blueberries"] = cropPrices["Blueberries"] * sellPercentage;
  cropSellValue["Carrots"] = cropPrices["Carrots"] * sellPercentage;
  cropSellValue["Beets"] = cropPrices["Beets"] * sellPercentage;
  cropSellValue["Tomatoes"] = cropPrices["Tomatoes"] * sellPercentage;
  itemPrices["Fertiliser"] = 5000.0f;
  itemPrices["Greenhouse"] = 50000.0f;
  itemModifier["Fertiliser"] = 0.5;
  itemModifier["Greenhouse"] = 1.25;
  weatherModifier["Rainfall"] = 1.0f;
  weatherModifier["Temperature"] = 1.0f;
}

// Buy fertiliser
void Shop::purchaseFertiliser(Player& player) {
  player.setMoney(itemPrices["Fertiliser"]);
  cropGrowthTime["Strawberries"] *= itemModifier["Fertiliser"];
  cropGrowthTime["Blueberries"] *= itemModifier["Fertiliser"];
  cropGrowthTime["Carrots"] *= itemModifier["Fertiliser"];
  cropGrowthTime["Beets"] *= itemModifier["Fertiliser"];
  cropGrowthTime["Tomatoes"] *= itemModifier["Fertiliser"];
}

// Buy greenhouse
void Shop::purchaseGreenhouse(Player& player) {
  player.setMoney(itemPrices["Greenhouse"]);
  sellPercentage += itemModifier["Greenhouse"];
}

std::string Shop::getItemVarStr(const std::string& itemName,
                                const std::string& variable) {
  if (variable == "Price") {
    std::ostringstream fertPriceStream;
    fertPriceStream << std::fixed << std::setprecision(2)
                    << itemPrices[itemName];  // Format to two decimal places
    std::string fertPriceString =
        fertPriceStream.str();  // Get the formatted string
    return fertPriceString;
  } else {
    std::ostringstream workerPriceStream;
    workerPriceStream << std::fixed << std::setprecision(2)
                      << itemModifier[itemName];
    std::string workerPriceString = workerPriceStream.str();
    return workerPriceString;
  }
}

float Shop::getItemPrice(const std::string& itemName) {
  return itemPrices[itemName];
}

int Shop::getCropVar(const std::string& cropName, const std::string& variable) {
  if (variable == "Price") {
    return cropPrices[cropName];
  } else if (variable == "Growth") {
    return cropGrowthTime[cropName] * weatherModifier["Rainfall"] *
           weatherModifier["Temperature"];
  } else {
    return cropSellValue[cropName];
  }
}

std::string Shop::getCropVarStr(const std::string& cropName,
                                const std::string& variable) {
  if (variable == "Price") {
    std::ostringstream priceStream;
    priceStream << std::fixed << std::setprecision(2) << cropPrices[cropName];
    std::string priceString = priceStream.str();
    return priceString;
  } else if (variable == "Growth") {
    std::ostringstream growthStream;
    growthStream << std::fixed << std::setprecision(2)
                 << cropGrowthTime[cropName] * weatherModifier["Rainfall"] *
                        weatherModifier["Temperature"];
    std::string growthString = growthStream.str();
    return growthString;
  } else {
    std::ostringstream sellStream;
    sellStream << std::fixed << std::setprecision(2) << cropSellValue[cropName];
    std::string sellString = sellStream.str();
    return sellString;
  }
}

void Shop::afterPurchaseCrop(const std::string& cropName) {
  // Increase the buy price
  cropPrices[cropName] = cropPrices[cropName] * increasePricePercentage;

  // Increase the sell price
  cropSellValue[cropName] = cropPrices[cropName] * sellPercentage;
}

void Shop::weatherAffected(float temperature, float rainfall) {
  temporaryTemperatureModifier = 1.0f;
  temporaryRainfallModifier = 1.0f;

  if (temperature > 30.0f) {  // If too hot decrease growth rate
    temporaryTemperatureModifier =
        ((temperature + 3) - 30.0f) *
        0.5;  // Add 3 to make sure growth rate is above 1
  } else if (temperature < 15.0f) {  // If too cold decrease growth rate
    temporaryTemperatureModifier =
        (15.0f - (temperature - 3)) *
        0.5;  // Subtract 3 to make sure growth is above 1
  }
  if (rainfall > 0) {  // If greater than 0 increase growth rate
    temporaryRainfallModifier = 0.6;
  }

  weatherModifier["Temperature"] = temporaryTemperatureModifier;
  weatherModifier["Rainfall"] = temporaryRainfallModifier;
}

std::string Shop::getWeatherModfiersStr(const std::string& cropName) {
  std::ostringstream weatherStream;
  weatherStream << std::fixed << std::setprecision(2)
                << weatherModifier[cropName];
  std::string weatherString = weatherStream.str();
  return weatherString;
}