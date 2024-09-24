#include "Weather.h"
#include <iostream>

int main() {
    Weather w1;
    w1.requestWeather();

    std::cout << "Location: " << w1.getLocation() << std::endl;
    std::cout << "Condition: " << w1.getCondition() << std::endl;
    std::cout << "Temperature: " << w1.getTemperature() << std::endl;
    std::cout << "Rainfall: " << w1.getRainfall() << std::endl;

    w1.setRainfall(0.5);
    w1.setTemperature(25);
    std::cout << "Manipulated Weather" << std::endl;
    std::cout << "Temperature: " << w1.getTemperature() << std::endl;
    std::cout << "Rainfall: " << w1.getRainfall() << std::endl;

}