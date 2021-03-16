#include <iostream>
#include "Eigen/Dense"
#include <Eigen/Core>


// #include "EigenUtils.h"
// template<typename Derived>
// void printMat(const Eigen::Matrix< Derived> &mat){
//     std::cout << mat.cols() << " " << mat.rows() << std::endl;
// }
int main(){
    Eigen::Matrix<double, 2, 3> M;
    M << 1, 2, 3, 4, 5, 6;
    // Eigen::Matrix<double, 2, 2> M;
    // M << 1, 2, 3, 4;

    Eigen::Map< Eigen::RowVectorXd> vec( M.data(), M.size());

    vec(0) = 10;
    std::cout << "vec: " << vec << std::endl;
    std::cout << "Mat: " << M << std::endl;
    // // Try the vectorize operator
    // auto vec = MatrixdToVecd< , 2>( M);

    std::cout << vec.segment( 2, 1) << std::endl;
    // std::cout << vec << std::endl;
}