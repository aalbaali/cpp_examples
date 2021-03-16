#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


int main(){
    std::string filename = "test.txt";
    {
        std::ofstream ostrm(filename);
        double d = 3.14;
        // ostrm.write(reinterpret_cast<char*>(&d), sizeof d); // binary output
        ostrm << 123 <<"\t"<< "abc" << std::endl;                      // text output
        ostrm << 123 <<"\t"<< "abc" << std::endl;                      // text output
    }

    // read back
    std::ifstream istrm(filename, std::ios::binary);
    double d;
    istrm.read(reinterpret_cast<char*>(&d), sizeof d);
    int n;
    std::string s;
    istrm >> n >> s;
    std::cout << " read back: " << d << " " << n << " " << s << '\n';


    std::stringstream ss;
    ss << "Hello_" << 23;
    std::string str = "2";
    ss >> str;
    std::cout << "String: " << str << std::endl;
}