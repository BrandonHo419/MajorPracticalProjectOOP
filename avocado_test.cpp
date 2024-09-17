#include "Avocado.h"
#include <iostream>

using namespace std;

int main() {
    avocado a;

    a.setGrowthSpeed();
    a.setPlantSpeed();
    a.setThirstRate();

    cout << "Avo growth rate " << a.getGrowthSpeed() << std::endl;
    cout << "Avo Plant speed " << a.getPlantSpeed() << std::endl;
    cout << "Avo Thirst Rate " << a.getPlantSpeed() << std::endl;

    return 0;
};