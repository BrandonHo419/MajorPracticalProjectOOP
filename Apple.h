#include "Crops.h" 
#ifndef APPLE_H
#define APPLE_H

class Apple : public Crops {
    private:

    protected:

    public:
    Apple();
    void setGrowthSpeed();
    void setPlantSpeed();
    void setThirstRate();
    ~Apple();
};

#endif
