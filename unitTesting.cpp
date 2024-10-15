#include "GridMap.h"
#include "Player.h"
#include "Crop.h"
#include "Carrots.h"
#include "Strawberries.h"
#include "Shop.h"

#include <gtest/gtest.h>


// Testing that grids are lcoked except for the one at (5,3)
TEST(GameTest, CreateGrid) {
    GridMap gridMap(10.0, 2, 10, 10, 0, 0);
    EXPECT_EQ(gridMap.getIsLocked(sf::Vector2u(5,3)), false);
    EXPECT_EQ(gridMap.getIsLocked(sf::Vector2u(5,4)), true);
    EXPECT_EQ(gridMap.getIsLocked(sf::Vector2u(0,0)), true);
}

// Testing that grids are purchased properly 
TEST(GameTest, CheckPurchase) {
    GridMap gridMap(10.0, 2, 10, 10, 0, 0);
    Player player(sf::Vector2f(5,3));

    EXPECT_EQ(gridMap.getIsLocked(sf::Vector2u(5,4)), true);
    gridMap.purchaseGrid(sf::Vector2u(5,4), player);
    EXPECT_EQ(gridMap.getIsLocked(sf::Vector2u(5,4)), false);
}

// Testing the logic for planting a crop and that before it is planted getHasCrop returns false
TEST(GameTest, BuyCarrot) {
    GridMap gridMap(10.0, 2, 10, 10, 0, 0);
    Player player(sf::Vector2f(5,3));
    Carrots *carrots = new Carrots(sf::Vector2f(5,3), 10, 10);
    EXPECT_EQ(gridMap.getHasCrop(sf::Vector2u(5,3)), false);
    gridMap.plantCrop(sf::Vector2u(5,3), carrots, player);
    EXPECT_EQ(carrots->getCropType(), "Carrots");
    EXPECT_EQ(carrots->getGrowthTime(), 10);
    carrots->setGrowthTime(0.12);
    EXPECT_FLOAT_EQ(carrots->getGrowthTime(), 0.12f);
    EXPECT_EQ(gridMap.getHasCrop(sf::Vector2u(5,3)), true);
}

// Testing that adding money works and when player purchases fertiliser it removes money correctly
TEST(GameTest, BuyFertiliser) {
    Player player(sf::Vector2f(5,3));
    Shop shop;
    EXPECT_EQ(player.getMoney(), 80);
    player.addMoney(10000); 
    shop.purchaseFertiliser(player);
    EXPECT_EQ(player.getMoney(), 5080);
}

// Testing buying a crop, deleting it than replanting on the now empty slot
TEST(GameTest, BuyThenDelete) {
    GridMap gridMap(10.0, 2, 10, 10, 0, 0);
    Player player(sf::Vector2f(5,3));
    Carrots *carrots = new Carrots(sf::Vector2f(5,3), 8, 8);
    gridMap.plantCrop(sf::Vector2u(5,3), carrots, player);
    EXPECT_EQ(carrots->getCropType(), "Carrots");
    gridMap.deleteCrop(sf::Vector2u(5,3));
    EXPECT_EQ(gridMap.getHasCrop(sf::Vector2u(5,3)), false);
    Strawberries *strawberry = new Strawberries(sf::Vector2f(5,3), 5, 5);
    EXPECT_EQ(strawberry->getCropType(), "Strawberries");
    gridMap.plantCrop(sf::Vector2u(5,3), strawberry, player);
    EXPECT_EQ(gridMap.getHasCrop(sf::Vector2u(5,3)), true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
