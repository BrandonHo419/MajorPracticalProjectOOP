#ifndef SHOP_H
#define SHOP_H

#include "Player.h"
#include <string>
#include <SFML/Graphics.hpp>

class Shop {
    public:
        Shop();
        void purchaseFertiliser(Player& player); // Purchase Fertiliser
        void purchaseGreenhouse(Player& player); // Purchase Greenhouse
        void purchaseWorkers(Player& player); // Purchase Workers
        std::string getFertiliserModifierStr(); // Retrieve fertiliser modifier as a string
        std::string getGreenhouseModifierStr(); // Retrieve greenhouse modifier as a string
        std::string getFertiliserPriceStr(); // Retrieve fertiliser price as a string
        std::string getGreenhousePriceStr(); // Retrieve greenhouse price as a string
        float getFertiliserPrice(); // Retrieve fertiliser price
        float getGreenhousePrice(); // Retrieve greenhouse price
        int getCropPrice(const std::string& cropName); // Retrieve crop price
        std::string getCropPriceStr(const std::string& cropName); // Retrieve crop price as a string
        int getCropGrowthTime(const std::string& cropName); // Retrieve crop growth time
        std::string getCropGrowthTimeStr(const std::string& cropName); // Retrieve crop growth time as a string
        int getCropSellValue(const std::string& cropName); // Retrieve crop sell value
        std::string getCropSellValueStr(const std::string& cropName); // Retrieve sell value as a string
        void afterPurchaseCrop(const std::string& cropName); // After purchasing a crop, increase price to values
    private:
        float fertiliser;
        float fertiliserPrice;
        float greenhouse;
        float greenhousePrice;
        const float workersPrice;
        float sellPercentage = 0.5f;
        const float increasePricePercentage = 1.20f;
        // Crop Prices
        std::map<std::string, float> cropPrices;
        std::map<std::string, float> cropGrowthTime;
        std::map<std::string, float> cropSellValue;
};
#endif