#include <iostream>
#include "Eigen/Dense"

int main(){
    Eigen::Matrix2d M;
    M << 1, 2, 3, 4;
    Eigen::Map<Eigen::RowVectorXd> v( M.data(), M.size());
    std::cout << v << std::endl;

    // Create a positive (semi)definite (covariance) matrix
    Eigen::Matrix2d S;
    S << 1, 0.5, 0.5, 2;
    // Create an arbitrary matrix A
    Eigen::Matrix2d A;
    A << 1, 2, 3, 4;
    // Solve the system S * X = A for X (i.e., X = S\A)
    auto X = S.ldlt().solve(A);

    std::cout << S * X - A << std::endl;

    // Solve the system Y * S = A for Y (i.e., Y = A/S)
    Eigen::Matrix2d Y = (S.ldlt().solve(A.transpose())).transpose();
    std::cout << Y * S - A<< std::endl;
    // std::cout << A << std::endl;
}