#include "vector.h"
#include <iostream>

template <class T> void print(Vector<T>& vec, const std::string& zinute) {
    std::cout << zinute << ": ";
    for (const auto& ele : vec)
        std::cout << ele << " ";
    std::cout << std::endl;
}
int main() {
    Vector<int> a(5, 10);

    print(a, "a po apbrėžimo");
    std::cout << "a.size(): " << a.size() << std::endl;
    std::cout << "a.capacity(): " << a.capacity() << "\n\n";
    a.resize(3);
    print(a, "a po a.resize(3)");
    std::cout << "a.size() po a.resize(3): " << a.size() << std::endl;
    std::cout << "a.capacity() po a.resize(3): " << a.capacity() << "\n\n";
    a.resize(8, 50);
    print(a, "a po a.resize(8, 50)");
    std::cout << "a.size() po a.resize(8, 50): " << a.size() << std::endl;
    std::cout << "a.capacity() po a.resize(8, 50): " << a.capacity() << "\n\n";
    a.reserve(15);
    std::cout << "a.size() po a.reserve(15): " << a.size() << std::endl;
    std::cout << "a.capacity() po a.reserve(15): " << a.capacity() << "\n\n";

    std::cout << "a.max_size() = " << a.max_size() << "\n\n";
    a.shrink_to_fit();
//    a.push_back(6);
    std::cout << "a.size() po a.shrink_to_fit(): " << a.size() << std::endl;
    std::cout << "a.capacity() po a.shrink_to_fit(): " << a.capacity() << "\n\n";
    a.resize(0);
    if (a.empty())
        std::cout << "a po a.resize(0) yra tuščias. " << std::endl;
    return 0;
}
