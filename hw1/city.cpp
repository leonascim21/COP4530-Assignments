//
// Created by leona on 5/22/2024.
//

#include "city.h"

std::ostream &operator<<(std::ostream &s, const City &c)
{
  s << c.name << " has a population of " << c.population;
  return s;
}


City::City()
{
  population = "0";
  name = "";
}


City::City(const std::string &Name, const std::string &Population)
{
  population = Population;
  name = Name;
}
