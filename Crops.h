#include <iostream>
#include <SFML/Graphics.hpp>
#ifndef CROPS_H
#define CROPS_H

using namespace std;
using namespace sf;

// Soon will need to inherit from technology (as a general overall modifier)

class Crops {
    private: // allocated these to private... 
        string avocado;
        string beetroot;
        string banana;
        string cherry;
        string apple;

    protected:
        // each crop will inherit these
        float modifier; // use for technology
        float growthSpeed;
        float plantSpeed;
        float thirstRate;
        
    public:
        Crops();
        float getGrowthSpeed();
        float getPlantSpeed();
        float getThirstRate();

        // 

        virtual bool isGrown();
        virtual void printInfo();
        ~Crops();
};

#endif
