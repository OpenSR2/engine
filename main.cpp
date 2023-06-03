#include <iostream>
#include <boost/filesystem.hpp>

int main() {
    std::cout << "Hello, World!" << std::endl;

    boost::filesystem::path path("opensr2");
    if (boost::filesystem::exists(path)) {
        std::cout << "File exists!" << std::endl;
    } else {
        std::cout << "File does not exist!" << std::endl;
    }

    return 0;
}
