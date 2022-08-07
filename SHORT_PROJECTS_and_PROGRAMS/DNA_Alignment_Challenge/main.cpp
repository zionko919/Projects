#include "ED.h"
#include <SFML/System.hpp>
#include <iostream>
#include <iomanip>
#include <string>


int main() {
    sf::Clock clock;
    sf::Time t;
    std::string string_1;
    std::string string_2;
    std::cin >> string_1 >> string_2;
    EditDistance test(string_1, string_2);
    int testResult = test.OptDistance();
    std::cout << test.Alignment() << std::endl;
    t = clock.getElapsedTime();
    std::cout << std::fixed;
    std::cout << std::setprecision(5);
    std::cout << "Edit Distance: " << testResult << std::endl;
    std::cout << "Execution Time: " << t.asSeconds()
<< " seconds\n" << std::endl;

    return 0;
}

