#ifndef WEATHER_H
#define WEATHER_H
#include <string>

class Weather {
 public:
    Weather();
    void requestWeather();
    float convertToFloat(std::string& stringValue);
    float getTemperature();
    float getRainfall();
    void removeSymbol(std::string& stringValue);
    std::string getLocation();
    std::string getTemperatureString();
    std::string getRainfallString();
    ~Weather();

  
 private:
    float temperature;
    float rainfall;
    std::string location;
    std::string temperatureStr;
    std::string rainfallStr;
};

#endif