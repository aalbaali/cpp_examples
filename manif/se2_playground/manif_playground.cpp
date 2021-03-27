
// manif
#include "manif/SE2.h"
#include "manif/Rn.h"

#include <iostream>

// Eigen namespace
using namespace Eigen;

// // std shortcuts and namespaces
// using std::cout;
// using std::endl;
// using std::vector;
// using std::map;
// using std::list;
// using std::pair;

// // Eigen namespace
// using namespace Eigen;

// manif namespace and shortcuts
// using manif::SE2d;
// using manif::SE2Tangentd;

static constexpr int DoF = manif::SE2d::DoF;
static constexpr int Dim = manif::SE2d::Dim;

// // some experiment constants
// static const int NUM_POSES      = 3;
// static const int NUM_LMKS       = 5;
// static const int NUM_FACTORS    = 9;
// static const int NUM_STATES     = NUM_POSES * DoF + NUM_LMKS    * Dim;
// static const int NUM_MEAS       = NUM_POSES * DoF + NUM_FACTORS * Dim;
// static const int MAX_ITER       = 20;           // for the solver

// This matrix can be used to define Jacobians on the Lie algebra (or tangent spaces).
typedef Matrix<double, DoF, DoF>    MatrixT;    // tangent-size square matrix
typedef Matrix<double, Dim, 1>      VectorB;    // landmark-size vector
typedef Matrix<double, Dim, DoF>    MatrixYT;   // measurement x tangent size matrix
typedef Matrix<double, Dim, Dim>    MatrixY;    // measurement-size square matrix
int main(){
    // Check SE2.h and SE2_base.h for further explanations.

    // ****************************************************************
    // Some generic properties
    // Dim: Dimension at which the Lie group element lives. For example, for SE2, Dim = 2. For SE3, Dim = 3. 
    std::cout << "SE2 has dimension: " << manif::SE2d::Dim << std::endl;
    // DoF: Degrees of freedom. Dimension of the Lie algebra element.
    std::cout << "SE2 has degree of freedom of : " << manif::SE2d::DoF << std::endl;
    
    // ****************************************************************
    
    // Some translation array to construct a pose;
    double r_ab_a[2] = {1, 2};
    // Some rotation scalar to construct a pose
    double th_ab = M_PI/4;

    // Define some arbitrary pose. The pose can be constructed using 2 scalars (for translation) and another scalar for rotation. Note that in the SE2 case, manif does not construct SE2 using a rotation matrix. However, for the SE3 case, it does in fact use rotation matrices to construct a pose.    
    manif::SE2d T_ba_ab( r_ab_a[0], r_ab_a[1], th_ab);

    
    // Try printing to terminal
    std::cout << "Some pose:\n" << T_ba_ab << std::endl;

    // A note about rotations in SE2. The SE2 struct does not deal with rotation matrices for rotation, instead, it relies on complex numbers. This is not a bad idea considering that in the SE2 case, a unit direction gives a unique rotation. 
    // Also, we can think of the two complex numbers as the first column of a rotation matrix! Specifically, if C\in SO2, then C(0,0)==real (the cosine part) and C(0,1) == complex (the sine part).

    // Access specific parts of pose
    std::cout << "Translation part of pose:\n" << T_ba_ab.translation() << std::endl;
    std::cout << "Rotation part of pose:\n" << T_ba_ab.rotation() << std::endl;
    std::cout << "Angle of rotation:\n" << T_ba_ab.angle() << std::endl;
    
    // To get the specific translation
    std::cout << "Translation in x: " << T_ba_ab.x() << std::endl;
    
    // ****************************************************************
    // Some operations

    // Acting on a vector (2D column matrix)
    Eigen::Vector2d v( 1.0, 0.0);
    // Acting on v
    std::cout << "T_ba_ab.act( v): \n" << T_ba_ab.act( v) << std:: endl;

    // Resolving v in the global  frame
    std::cout << "T_ba_ab.rotation() * v:\n" << T_ba_ab.rotation() * v << std::endl;

    // Resolving v in the local frame
    std::cout << "T_ba_ab.inverse().rotation() * v:\n" << T_ba_ab.inverse().rotation() * v << std::endl;

    // ****************************************************************
    // Jacobians
    // Say we have position in local frame r_za_a that we want to express in the local frame of the robot. I.e., we want r_zb_b. Then we have
    //  r_za_a = T_ab_b\inv * r_za_a
    // Note that r_za_a is w.r.t. homogenous coordinates which we're dismissing here; we can simply use the .act() method.

    // Generate some arbitrary r_za_a
    VectorB r_za_a;
    r_za_a << 1.5, 0.5;

    // Transform to r_zb_b
    VectorB r_zb_b;
    // Jacobians
    MatrixT J_ix_x;
    MatrixYT J_rzbb_ix;
    MatrixY J_rzbb_rzaa;
    r_zb_b = T_ba_ab.inverse( J_ix_x).act( r_za_a, J_rzbb_ix, J_rzbb_rzaa);
    // Jacobian of r_zb_b w.r.t. X (xi)
    MatrixYT J_rzbb_x = J_rzbb_ix * J_ix_x;

    // Display output
    std::cout << "r_za_a : " << r_za_a.transpose() << std::endl;
    std::cout << "r_zb_b : " << r_zb_b.transpose() << std::endl;
    // Jacobians
    std::cout << "J_rzbb_x\n" << J_rzbb_x << std::endl;
    std::cout << "J_rzbb_rzaa\n" << J_rzbb_rzaa << std::endl;

    // ****************************************************************
    // Generate random numbers. These are UNIFORMLY distributed random numbers (between -1 and 1).
    std::cout << "Random SE2 element:\n" << std::endl;
    std::cout << manif::SE2d::Random() << std::endl;
}