#include "Weather.h"
#include <array>
#include <cctype>
#include <iostream>
#include <sstream>
#include <cstdlib>

Weather::Weather(): temperature(0), rainfall(0), location(""), temperatureStr(""), rainfallStr("") {};

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
  std::string citiesAustralia[8] = {"Adelaide","Canberra","Sydney","Brisbane","Melbourne","Hobart","Perth","Darwin"};

  // Sets a random city of Australia
  srand(time(0));
  int randomNum = rand() % 8;
  this->location= citiesAustralia[randomNum];
  
  std::string cmd = "./requestWeather.sh ";
  // Concatenates cmd and userLocation
  cmd += this->location;

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

  // Split the result into separate variables (temperature, and
  // rainfall)
  std::istringstream iss(result);

  std::getline(iss, this->temperatureStr);  // Get the first line (temperature)
  std::getline(iss, this->rainfallStr);     // Get the second line (rainfall)

  removeSymbol(this->temperatureStr);

  // Convert temperature and rainfall to floats
  this->temperature = convertToFloat(temperatureStr);  // Extract numeric value from temperature
  this->rainfall = convertToFloat(rainfallStr);  // Extract numeric value from rainfall
};

void Weather::removeSymbol(std::string& stringValue) { // Remove the Celcius symbol with Degrees Celcius
    if (stringValue.size() >= 3) {  // Check if the string is long enough
        stringValue.resize(stringValue.size() - 3);
    }
    // Append the new string as intended
    std::string string = " Degrees Celcius"; 
    stringValue.append(string); // Particular fonts can't support the celcius symbol
}

float Weather::getTemperature() {
    return temperature;
};

std::string Weather::getLocation() {
  return location;
};

float Weather::getRainfall() {
    return rainfall;
};

std::string Weather:: getTemperatureString() {
  return temperatureStr;
};

std::string Weather:: getRainfallString() {
  return rainfallStr;
};
