#include "Silicon/system.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    // Early engine demo.

    for (std::string i : Silicon::tools::seperate("Hello World Data IS Here!",' ')) {
        std::cout << i << "\n";
    }
}
