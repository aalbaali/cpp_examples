#include <iostream>
#include "Eigen/Dense"

#include <functional>

const size_t dim_u = 1;
const size_t dim_x = 2;

typedef Eigen::Matrix<double, dim_x, 1>     ColMatX;
typedef Eigen::Matrix<double, dim_u, 1>     ColMatU;
typedef Eigen::Matrix<double, dim_x, dim_x> MatrixA;
typedef Eigen::Matrix<double, dim_x, dim_u> MatrixB;

// I'll create a function and pass it to another function
ColMatX process_model( ColMatX x_km1, ColMatU u_km1, MatrixA A, MatrixB B){
    return A * x_km1 + B * u_km1;
}

// A function that propagates estimates
ColMatX propagate( ColMatX x_km1, ColMatU u_km1, std::function<ColMatX(ColMatX, ColMatU)> process_model){
    return process_model( x_km1, u_km1);
}

int main(){
    // Define process model matrices
    MatrixA A;
    MatrixB B;
    // Initialize process model matrices
    A.setIdentity();
    B.setIdentity();

    // Define state and control input
    ColMatX x_0;
    ColMatU u_0;
    // Initialize them
    x_0.setZero();
    u_0.setIdentity();

    std::cout << "x_0':\t" << x_0.transpose() << std::endl;
    std::cout << "u_0':\t" << u_0.transpose() << std::endl;

    // Compute x_1 using the process model directly (need to provide the A and B matrices)
    ColMatX x_1 = process_model( x_0, u_0, A, B);
    std::cout << "Using process model directly: x_1':\t" << x_1.transpose() << std::endl;

    // Define a function that binds the process model to A and B
    std::function<ColMatX(ColMatX, ColMatU)> linear_process_model = std::bind(process_model, std::placeholders::_1, std::placeholders::_2, A, B);

    // Note that you do NOT need to pass the A and B matrices when using the binded linear_process_model function.
    ColMatX x_1_f = linear_process_model( x_0, u_0);
    std::cout << "Using functional bindings: x_1':\t" << x_1_f.transpose() << std::endl;
}
