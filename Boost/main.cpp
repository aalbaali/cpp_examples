#include <iostream>
#include <boost/format.hpp>

using boost::format;

int main() {
  format fmtr("%-25s [%5.2f, %8.2f]\n");
  std::cout << fmtr % "Position1" % 1.123 % 21.34567;
  std::cout << fmtr % "Position1 abs" % 1.123 % 21.34567;
  std::cout << fmtr % "Position2 asd fsd" % 1.123 % 1221.34567;
  std::cout << fmtr % "Position2 asd fsd" % 11.123 % 1221.34567;
}