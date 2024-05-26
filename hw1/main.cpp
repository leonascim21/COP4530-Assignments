#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "city.h"

std::string DeleteWhiteSpace(std::string s);

int main()
{
  //OPEN INPUT FILE
  std::ifstream infile;
  std::cout << "Enter the name of the input file?\n>";
  std::string filename;
  std::cin >> filename;
  infile.open(filename);
  std::cin.ignore();

  //END PROGRAM IF FILE IS NOT FOUND
  if (!infile.is_open())
  {
    std::cout << "Error: Unable to open file. \n";
    return 1;
  }

  std::cout << "Enter the initial letters of a city to find its similarly named cities, ranked by population (this is case-sensitive)\n\n";
  std::string user_input;
  std::getline(std::cin, user_input);

  while(user_input != "^D")
  {

    std::list<City> matches_list;
    int i = 0;

    while(!infile.eof())
    {
      std::string file_input;
      std::getline(infile, file_input);

      //IF STATEMENT TO PREVENT CRASHING IF A BLANK LINE IS READ IN
      if(file_input.size() > 15)
      {
        //FORMATTED_FILE_INPUT HOLDS THE FIRST N CHARACTERS OF THE NAME OF THE LINE READ IN
        //DEPENDING ON THE SIZE OF THE USER INPUT
        std::string formatted_file_input = file_input.substr(15);
        formatted_file_input = formatted_file_input.substr(0, user_input.size());

        //FOR FIRST 10 MATCHES ADD THEM TO THE END LIST
        if(formatted_file_input == user_input && ++i<10)
        {
          City match(file_input.substr(15), DeleteWhiteSpace(file_input.substr(0,15)));
          matches_list.push_back(match);
        }
      }
    }

    //PRINT CITY LIST
    int j = 0;
    for(City& city : matches_list)
    {
      std::cout << ++j << ") " << city << std::endl;
    }


    std::cout << "\nAnother City? (use CTRL-D to exit)\n\n";
    std::cin >> user_input;
    //RESET FILE
    infile.close();
    infile.open(filename);
  }

  return 0;
}

std::string DeleteWhiteSpace(std::string s)
{
  while(s[0] == ' ')
  {
    s = s.substr(1,s.size());
  }
  return s;
}
