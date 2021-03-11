#include <iostream> // Include this for displaying to terminal

#include "Eigen/Dense"

// To use matrix functions, which are then used to generate random vectors
#include "unsupported/Eigen/MatrixFunctions"

// To generate random numbers
#include <random>

#include <vector>

int main(){
    // Set number of trials
    const int N = 1e4;

    // Set the random number generator
    std::default_random_engine generator;
    // Set the distribution to be the STANDARD normal random variable
    std::normal_distribution< double> distribution{ 0., 1.};
    // Create a lambda function to generate standard normal random variables. This is in turn used to generate random vectors
    auto randn = [&](){ return distribution( generator);};

    // **************************************************
    //      First, generate standard random scalars
    {
        // Variable to store sum of samples, then divided by number of trials N
        double sample_mean = 0.;
        double sample_var = 1.;
        for (int i = 0; i < N; i++){
            // Sample from standard distribution
            double rn = randn();
            // Sum random variables
            sample_mean += rn;
            // Compute variance
            sample_var += std::pow( rn, 2.0);
        }
        // Get the mean
        sample_mean /= static_cast<float>( N);
        sample_var  /= static_cast<float>( N);

        std::cout << "Scalar:\tsample mean:\t" << sample_mean << std::endl;
        std::cout << "Scalar:\tsample var :\t" << sample_var  << std::endl;
    }

    // **************************************************
    //      Second, the vector case
    {
        // Creat a mean vector
        Eigen::Vector3d sample_mean;
        sample_mean.setZero();
        // Covariance matrix
        Eigen::Matrix3d sample_cov;
        // Set to identity for now
        sample_cov.setIdentity();

        // Generate samples
        for (int i = 0; i < N; i++){
            // Draw samples from the multivariate STANDARD NORMAL distribution
            Eigen::Vector3d vec_sample = Eigen::Vector3d::NullaryExpr( 3, randn);

            // Add to the sample mean
            sample_mean += vec_sample;
            // Add to the sample covaraince
            sample_cov += vec_sample * vec_sample. transpose();
        }

        // Compute mean
        sample_mean /= static_cast< double > ( N );
        sample_cov  /= static_cast< double > ( N );
        std::cout << "Vector:\tStandard sample mean:\t" << sample_mean.transpose() << std::endl;
        std::cout << "Vector:\tStandard sample cov :\n" << sample_cov              << std::endl;
    }

    // **************************************************
    //      Third, the general case
    {
        // Set the true mean
        Eigen::Vector3d mean_true( 1, 2, 3);
        // Generate some arbitrary covariance matrix
        Eigen::Matrix3d cov_true;
        {
            Eigen::Matrix3d mat;
            // Generate random matrix (not symmatric)
            mat.setRandom();
            // Create a positive definite matrix from the random matrix using expm(M + M') > 0
            cov_true = ( mat + mat.transpose() ). exp();
        }
        // Take the Cholesky lower triangular matrix
        Eigen::Matrix3d L_cov_true = cov_true.llt().matrixL();

        // Vectors of the sampled vectors
        std::vector< Eigen::Vector3d> vec_samples( N);
        // Sample mean vector
        Eigen::Vector3d sample_mean;
        for (int i = 0; i < N; i++){
            vec_samples[i] = mean_true + L_cov_true * ( Eigen::Vector3d::NullaryExpr( 3, randn));
            sample_mean += vec_samples[i];
        }
        // Compute the sample mean
        sample_mean /= static_cast< double> (N);
        // Compute sample covariance
        Eigen::Matrix3d sample_cov;
        for ( int i = 0; i < N; i++){
            Eigen::Vector3d sample = vec_samples[ i] - sample_mean;
            sample_cov +=  sample * sample.transpose();
        }
        // Normalize
        sample_cov = sample_cov / (N - 1);

        std::cout << "Vector:\tSample mean - true mean:\t" << ( sample_mean - mean_true) . transpose() << std::endl;
        std::cout << "Vector:\tSample cov  - true cov :\n" << ( sample_cov - cov_true) << std::endl;
    }
}