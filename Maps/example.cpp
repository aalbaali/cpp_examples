#include <iostream>
#include <map>
#include <string>

// Define a string to double map
// typdef std::map< std::string, double> MapStrToDouble;
int main(){
    std::map< std::string, int> age;

    age["amro"] = 24;
    age["bb"] = 27;
    age["bb"] = 29;
    for( auto i : age){
        std::cout << "Key:\t" << i.first << "\t" << ". Value:\t" << i.second << std::endl;
    }

    std::map< std::string, int> sz = {{"x", 2}, {"y", 3}};
    for( auto i : sz){
        std::cout << "Key:\t" << i.first << "\t" << ". Value:\t" << i.second << std::endl;
    }
}