#include <iostream>
#include "Eigen/Dense"
#include "unsupported/Eigen/MatrixFunctions"

// To generate random numbers
#include <random>


// Set the random number generator
std::default_random_engine generator;
// Set the distribution to be the STANDARD normal random variable
std::normal_distribution< double> distribution{ 0., 1.};

// Scalar random number generator
double randn(){
    return distribution( generator);
}


Eigen::VectorXd randn(Eigen::VectorXd vec){    
    return vec.NullaryExpr( vec.rows(), [&](){ return distribution( generator);});
}

int main(){
    // Example: get a single scalar
    std::cout << randn() << std::endl;

    // // Example 
    // std::cout << randn(Eigen::Vector2d) << std::endl;
    Eigen::Vector3d vec;
    vec.setZero();
    std::cout << randn( vec).transpose() << std::endl;
    std::cout << vec.transpose() << std::endl;
}
