#ifndef WEATHER_H
#define WEATHER_H
#include <string>

class Weather {
 public:
    Weather();
    void requestWeather();
    float convertToFloat(std::string& stringValue);
    float getTemperature();
    std::string getCondition();
    std::string getLocation();
    float getRainfall();
    void setTemperature(float userTemperature);
    void setRainfall(float userRainfall);

  
 private:
    float temperature;
    std::string condition;
    std::string location;
    float rainfall;

};

#endif