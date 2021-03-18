#include <iostream>
#include <functional>

double add( double x1, double x2){ return x1 + x2;}
double sub( double x1, double x2){ return x1 - x2;}

double binaryOperation( double x1, double x2, std::function<double(double, double)> binaryFunc){ return binaryFunc( x1, x2);}

int main(){
    // Set a function using Lambda function that returns a constant value
    std::function<double()> OnePlusTwo = [](){return add(1, 2);};
    std::cout << OnePlusTwo() << std::endl;

    // A function that increments a double. We'll this functional using two ways:
    //      1. using lambdas, and
    //      2. using std::bind and the custom `add` function defined above
    std::function<double( double)> AddOne;
    
    // 1. Define using lambdas
    AddOne = [](double x){return ++x;};
    std::cout << "55 + 1 = " << AddOne( 55.0) << std::endl;

    // 2. define using the custom `add` function
    AddOne = std::bind( add, 1, std::placeholders::_1);
    std::cout << "65 + 1 = " << AddOne( 65.0) << std::endl;

    // ****************************
    // Binding a function argument.

    // 1. Simply CALL the binaryOperation function using the `add` function as the binary operator
    std::cout << "100 + 50 = " << binaryOperation( 100, 50, &add) << std::endl;
    // 2. Set a function using funcational to binaryOperation where SOME (the binary operator) of its arguments are BOUND (or binded?) to some value (in this case, bound to using the custom `add` binary operator)
    std::function<double(double, double)> AddBind = std::bind( binaryOperation, std::placeholders::_1, std::placeholders::_2, &add);
    std::cout << "200 + 50 = " << AddBind( 200, 50) << std::endl;
}