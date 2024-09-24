#include "Weather.h"
#include <array>
#include <cctype>
#include <iostream>
#include <sstream>
#include <cstdlib>

Weather::Weather(): temperature(0), rainfall(0), condition(""), location("") {};

float Weather::convertToFloat(std::string& stringValue) {
  std::string numericIndex;
  for (int i : stringValue) {
    if (isdigit(i) || i == '.' ||
        i == '-') {  // Include negative numbers and decimals
      numericIndex += i;
    }
  }
  return std::stof(numericIndex);
};

void Weather::requestWeather() {
  std::string location;
  std::string citiesAustralia[8] = {"Adelaide","Brisbane","Sydney","Hobart","Canberra","Darwin","Perth","Melbourne"};

  // Sets a random city of Australia
  srand(time(0));
  int randomNum = rand() % 7;
  this->location= citiesAustralia[randomNum];
  

  std::string cmd = "./requestWeather.sh ";
  // Concatenates cmd and userLocation
  cmd += location;

  // Open a pipe to run the command and capture the output
  std::array<char, 128> buffer;
  std::string result;
  FILE* pipe = popen(cmd.c_str(), "r");
  if (!pipe) {
    std::cerr << "Failed to run script!" << std::endl;
  }

  // Read the output from the script into the result string
  while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
    result += buffer.data();  // Append the output to the result string
  }

  // Close the pipe
  pclose(pipe);

  // Output the full result (for testing)
  std::cout << "Weather Information from bash file: " << result << std::endl;

  // Split the result into separate variables (weather, temperature, and
  // rainfall)
  std::istringstream iss(result);
  std::string condition, temperatureStr, rainfallStr;

  std::getline(iss, this->condition);    // Get the first line (weather condition)
  std::getline(iss, temperatureStr);  // Get the second line (temperature)
  std::getline(iss, rainfallStr);     // Get the third line (rainfall)

  // Convert temperature and rainfall to floats
  this->temperature = convertToFloat(temperatureStr);  // Extract numeric value from temperature
  this->rainfall = convertToFloat(rainfallStr);  // Extract numeric value from rainfall
};

float Weather::getTemperature() {
    return temperature;
};

std::string Weather::getCondition() {
    return condition;
};

std::string Weather::getLocation() {
  return location;
}

float Weather::getRainfall() {
    return rainfall;
}

void Weather::setTemperature(float userTemperature) {
  this->temperature = userTemperature;
};

void Weather::setRainfall(float userRainfall) {
  this->rainfall = userRainfall;
}