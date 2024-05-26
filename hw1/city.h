//
// Created by leona on 5/22/2024.
//

#ifndef CITY_H
#define CITY_H

#include<string>
#include <iostream>


class City
{

friend std::ostream &operator<<(std::ostream &s, const City &c);

public:
  City();
  City(const std::string &Name, const std::string &Population);

private:
  std::string population;
  std::string name;
};



#endif //CITY_H
