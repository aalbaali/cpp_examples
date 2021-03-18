#include <iostream>
#include <string> // Used to demonstrate an example
#include <tuple>
// Tuple is mainly used in functions to return multiple types

// Function that returns a an string and a double
std::tuple<std::string, int> getStudentNameAndID()
{ 
//   return std::tuple<std::string, int>{"Amr", 9840}; // Always works
  return std::make_tuple("Amro", 235); // Also works
}

int main(){
    auto student = getStudentNameAndID();

    // That's how to extract the values
    std::cout << "Name:\t" << std::get<0>(student) << std::endl;
    std::cout << "ID:\t"  << std::get<1>(student) << std::endl;

    // Another way to do this is using std::tie
    std::string student_name;
    int    student_id;
    std::tie(student_name, student_id) = student;
    std::cout << "\nName:\t" << student_name << std::endl;
    std::cout << "ID:\t"     << student_id << std::endl;
}