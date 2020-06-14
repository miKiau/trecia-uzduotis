#include "vector.h"
#include <vector>
#include <iostream>

template <class T> void print(std::vector<T>& vec, const std::string& zinute) {
    std::cout << zinute << ": ";
    for (const auto& ele : vec)
        std::cout << ele << " ";
    std::cout << std::endl;
}
template <class T> void print(Vector<T>& vec, const std::string& zinute) {
    std::cout << zinute << ": ";
    for (const auto& ele : vec)
        std::cout << ele << " ";
    std::cout << std::endl;
}

typedef std::vector<int> V;
typedef Vector<int> V1;

int main() {
    // Palyginti mano sukurtą vektoriu su standartiniu reikia tik pakeisti is V1 į V
    V1 a(5, 10);

    print(a, "a atspausdinimas po apbrėžimo naudojant begin() ir end(): ");
    std::cout << "a atspausdinimas naudojant rbegin() ir rend(): ";
    for (auto i = a.rbegin(), until = a.rend(); i < until; ++i)
        std::cout << *i << " ";
    std::cout << "\na atspausdinimas naudojant operatorių []: ";
    for (int i = 0, until = a.size(); i < until; ++i)
        std::cout << a[i] << " ";
    std::cout << "\na atspausdinimas naudojant funkciją at(): ";
    for (int i = 0, until = a.size(); i < until; ++i)
        std::cout << a.at(i) << " ";

    std::cout << "\n\n";
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
    std::cout << "a.size() po a.shrink_to_fit(): " << a.size() << std::endl;
    std::cout << "a.capacity() po a.shrink_to_fit(): " << a.capacity() << "\n\n";
    print(a, "a prieš a.push_back(6)");
    a.push_back(6);
    print(a, "a po a.push_back(6)");
    std::cout << "a.size() po a.push_back(6): " << a.size() << std::endl;
    std::cout << "a.capacity() po a.push_back(6): " << a.capacity() << "\n\n";

    a.resize(0);
    if (a.empty())
        std::cout << "a po a.resize(0) yra tuščias. " << std::endl;

//    a.~Vector();
//    std::cout << "a.size() po a.~Vector(): " << a.size() << std::endl;
//    std::cout << "a.capacity() po a.~Vector(): " << a.capacity() << "\n\n";
    return 0;
}
