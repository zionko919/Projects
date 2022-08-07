#include "MModel.h"
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    srand(time(NULL));
    int k = atoi(argv[1]);
    int length = atoi(argv[2]);

    std::string text;
    std::string temp;
    std::getline(std::cin, text);

    MModel testGen(text, k);

    std::cout << testGen.generate(text.substr(0, k), length) << std::endl;
    return 0;
}

