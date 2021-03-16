#include <iostream>
#include "Eigen/Eigen"


int main(){
    // Create some symmetric matrix
    Eigen::Matrix2d M;
    M << 0, 1, 1, 2;
    // Add some noise on the bottom left element
    M(1,0) += 1e-2;

    std::cout << "Before ensuring symmetry" << std::endl;
    std::cout << M << std::endl;

    // Ensure symmetry
    auto M2 = 0.5 * (M + M.transpose());

    std::cout << "After ensuring symmetry" << std::endl;
    std::cout << M2 << std::endl;
}