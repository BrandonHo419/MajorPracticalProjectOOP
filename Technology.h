#include <iostream>
#include <SFML/Graphics.hpp>
#ifndef TECHNOLOGY_H
#define TECHNOLOGY_H

using namespace std;

class Technology {
    private:

    protected:
        string cropTech; // Will be used locally
        string moneyTech; // Will be used locally
        int cropModifier;
        int moneyModifier;
        int baseModifier; // BaseModifier added

    public:
        Technology();
        // Don't think any of these are needed
        void setGlobalCropModifier();
        void setGlobalMoneyModifier();
        void setBaseModifier();

        string getCropTech(); // the logic for the string: (name), int = modifierValue
        string getMoneyTech();
        int getCropModifier();
        int getMoneyModifier();

        ~Technology();

};

#endif