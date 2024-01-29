#include <string>
class Config
{
  public:
    Config();
    std::pair <int,int> getConfig(std::string configFile);
    std::vector <std::pair <std::string,int> > getBoatConfig(std::string configFile);

    
    std::string configFile;

};