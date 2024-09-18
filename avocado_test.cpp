#include "Avocado.h"
#include <iostream>

using namespace std;

int main() {
    avocado a;

    a.setSpeed();


    cout << "Avo growth rate " << a.getSpeed() << std::endl;

    return 0;
};