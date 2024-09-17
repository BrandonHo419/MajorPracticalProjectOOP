#include "Crops.h" 
#ifndef AVOCADO_H
#define AVOCADO_H

class avocado : public Crops{ // inherits public so the public and protected members of the base class are public in the derived class
    private:

    protected:

    public:
    avocado();
    void setGrowthSpeed();
    void setPlantSpeed();
    void setThirstRate();
    ~avocado();
};

#endif