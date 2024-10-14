#ifndef WEATHER_H
#define WEATHER_H
#include <string>

class Weather {
 public:
  Weather();              // Weather Initialiser
  void requestWeather();  // Requests weather from Ubuntu's wttr API
  float convertToFloat(
      std::string& stringValue);  // Converts the string result into a float
  float getTemperature();         // Returns temperature
  float getRainfall();            // Returns rainfall
  void removeSymbol(
      std::string& stringValue);  // Remove symbols that the font cant support
  std::string getLocation();      // Returns location
  std::string getTemperatureString();  // Returns temperature as a string
  std::string getRainfallString();     // Returns rainfall as a string
  ~Weather();

 private:
  std::string location;
  std::string temperatureStr;
  std::string rainfallStr;

 protected:
  float temperature;
  float rainfall;
};

#endif