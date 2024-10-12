#include "Shop.h"
#include <iostream>
#include <iomanip>
#include <sstream>


Shop::Shop()
    : fertiliser(0.5),
      fertiliserPrice(5000), 
      greenhouse(1.25),
      greenhousePrice(10000),
      workersPrice(20000) {
     // Initialize crop prices, growth time and sell value
    cropPrices["Strawberries"] = 10.0f;
    cropPrices["Blueberries"] = 150.0f;
    cropPrices["Carrots"] = 450.0f;
    cropPrices["Beets"] = 1500.0f;
    cropPrices["Tomatoes"] = 5000.0f;
    cropGrowthTime["Strawberries"] = 2.0f;
    cropGrowthTime["Blueberries"] = 3.5f;
    cropGrowthTime["Carrots"] = 4.5f;
    cropGrowthTime["Beets"] = 5.5f;
    cropGrowthTime["Tomatoes"] = 6.5f;
    cropSellValue["Strawberries"] = cropPrices["Strawberries"] * sellPercentage;
    cropSellValue["Blueberries"] = cropPrices["Blueberries"] * sellPercentage;
    cropSellValue["Carrots"] = cropPrices["Carrots"] * sellPercentage;
    cropSellValue["Beets"] = cropPrices["Beets"] * sellPercentage;
    cropSellValue["Tomatoes"] = cropPrices["Tomatoes"] * sellPercentage;
    }

// Buy fertiliser
void Shop::purchaseFertiliser(Player& player) {
    player.setMoney(fertiliserPrice);
    cropGrowthTime["Strawberries"] *= fertiliser;
    cropGrowthTime["Blueberries"] *= fertiliser;
    cropGrowthTime["Carrots"] *= fertiliser;
    cropGrowthTime["Beets"] *= fertiliser;
    cropGrowthTime["Tomatoes"] *= fertiliser;
}

// Buy greenhouse
void Shop::purchaseGreenhouse(Player& player) {
    player.setMoney(greenhousePrice);
    sellPercentage += greenhouse;
}

// Buy workers   
void Shop::purchaseWorkers(Player& player) {
    player.setMoney(workersPrice);
}

std::string Shop::getFertiliserModifierStr() {
    std::ostringstream fertStream;
    fertStream << std::fixed << std::setprecision(2) << fertiliser; // Format to two decimal places
    std::string fertString = fertStream.str(); // Get the formatted string
    return fertString;
}

std::string Shop::getGreenhouseModifierStr() {
    std::ostringstream ghouseStream;
    ghouseStream << std::fixed << std::setprecision(2) << greenhouse; 
    std::string ghouseString = ghouseStream.str(); 
    return ghouseString;
}

std::string Shop::getFertiliserPriceStr() {
    std::ostringstream fertPriceStream;
    fertPriceStream << std::fixed << std::setprecision(2) << fertiliserPrice;
    std::string fertPriceString = fertPriceStream.str();
    return fertPriceString;
}

std::string Shop::getGreenhousePriceStr() {
    std::ostringstream ghousePriceStream;
    ghousePriceStream << std::fixed << std::setprecision(2) << greenhousePrice;
    std::string ghousePriceString = ghousePriceStream.str(); 
    return ghousePriceString;
}

float Shop::getFertiliserPrice() {
    return fertiliserPrice;
}

float Shop::getGreenhousePrice() {
    return greenhousePrice;
}

int Shop::getCropPrice(const std::string& cropName) {
    return cropPrices[cropName];
}

std::string Shop::getCropPriceStr(const std::string& cropName) {
    std::ostringstream priceStream;
    priceStream << std::fixed << std::setprecision(2) << cropPrices[cropName];
    std::string priceString = priceStream.str();
    return priceString;
}

void Shop::afterPurchaseCrop(const std::string& cropName) {
    // Increase the buy price by 120%
    cropPrices[cropName] = cropPrices[cropName] * increasePricePercentage;

    // Increase the sell price by 50%
    cropSellValue[cropName] = cropPrices[cropName] * sellPercentage;
}

int Shop::getCropSellValue(const std::string& cropName) {
    return cropSellValue[cropName];
}

std::string Shop::getCropSellValueStr(const std::string& cropName) {
    std::ostringstream sellStream;
    sellStream << std::fixed << std::setprecision(2) << cropSellValue[cropName];
    std::string sellString = sellStream.str();
    return sellString;
}

int Shop::getCropGrowthTime(const std::string& cropName) {
    return cropGrowthTime[cropName];
}

std::string Shop::getCropGrowthTimeStr(const std::string& cropName) {
    std::ostringstream growthStream;
    growthStream << std::fixed << std::setprecision(2) << cropGrowthTime[cropName];
    std::string growthString = growthStream.str();
    return growthString;
}