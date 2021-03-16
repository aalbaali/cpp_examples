#include <iostream>
#include <vector>
#include <array>


// Function that returns an arbitrary vector?
template<typename T>
std::vector<std::vector<T>> getVect(){
    std::vector<T> vv( 3);
    vv[0] = 1.5;
    vv[1] = 10;
    vv[2] = 5;

    std::vector< std::vector< T>> dd(3);
    dd[0] = vv;
    return dd;
}

int main(){

    auto vv = getVect<int>();
    for( auto i : vv){
        for( auto j : i){
            std::cout << j << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::vector<int> int_vec;

    // int_vec.push_back( 2);
    // int_vec.push_back( 3);
    // int_vec.push_back( 5);

    int_vec.resize( 3);
    int_vec[0] = 1;
    int_vec[2] = 5;
    int_vec[3] = 8;

    for(auto i : int_vec)
        std::cout << i << "\t";
    std::cout << std::endl;

    // Vector of vectors
    std::vector< std::vector<int> > vvec;
    vvec.push_back( std::vector<int> {1, 2, 3});
    vvec.push_back( std::vector<int> {3});
    vvec.push_back( std::vector<int> {100, 5, 1});
    
    // Go over each element
    std::cout << "\nVector of vectors:" << std::endl;
    for( auto i : vvec){
        for( auto j : i){
            std::cout << j << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "\nEnd of vector demonstrations\n" << std::endl;
    std::cout << "Go over each int element" << std::endl;    
    // for(size_t i = 0; i < vvec.size(); i++){
    for(size_t i = 0; i < vvec.size(); i++){
        std::cout << "idx " << i << ": ";
        std::cout << vvec[i][0] << "\t";
    }
    std::cout << "\n" << std::endl;

    // ******************************
    // Arrays
    std::array< int , 3> int_arr;
    int_arr[0] = 1;
    int_arr[1] = 2;
    // int_arr[3] = 3; // Would give an error
    std::cout << "Size: " << int_arr.size() << std::endl;
}