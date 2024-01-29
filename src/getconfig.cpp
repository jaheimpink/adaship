#include "../headers/adaship.h"

Config::Config()
{
  configFile = "adaship_config.ini";
}

std::pair<int, int> Config::getConfig(std::string configFile)
{
  std::string line;
  std::string value;
  std::string delimiter = ":";

  std::ifstream config(configFile);

  while (getline(config, line))
  {
    value = line.substr(0, line.find(delimiter));
    if (value == "Board")
    {
      delimiter = " ";
      std::pair<int, int> dimensionConfig;

      std::string dimensionsL = line.erase(0, line.find(delimiter) + 1);
      std::string dimensionsH = line.erase(0, line.find(delimiter) + 1);
      std::string length = dimensionsL.erase(line.find("x"), dimensionsL.length());
      std::string height = dimensionsH.erase(line.find(length), line.find("x") + 1);
      int configLength = std::stoi(length);
      int configHeight = std::stoi(height);
      dimensionConfig = std::make_pair(configLength, configHeight);
      return dimensionConfig;
    }
  }
}

std::vector<std::pair<std::string, int>> Config::getBoatConfig(std::string configFile)
{
  std::string line;
  std::string value;
  std::string delimiter;
  std::vector<std::pair<std::string, int>> fleet;

  std::ifstream config(configFile);
  while (getline(config, line))
  {
    delimiter = ":";
    value = line.substr(0, line.find(delimiter));
    if (value == "Boat")
    {
      delimiter = " ";
      std::string alternateDelimiter = ",";
      std::pair<std::string, int> boatConfig;

      std::string boatDetails = line.erase(0, line.find(delimiter) + 1);
      std::string boatName = boatDetails.substr(0, line.find(alternateDelimiter));
      std::string boatLength = boatDetails.substr(line.find(alternateDelimiter) + 1);

      int boatSize = std::stoi(boatLength);
      boatConfig = std::make_pair(boatName, boatSize);

      fleet.push_back(boatConfig);
    }
  }
  return fleet;
}
