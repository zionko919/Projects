#include <stdint.h>
#include <math.h>
#include <string>
#include <exception>
#include <vector>
#include <iostream>
#include "StringSound.h"

#define SR 441000

StringSound::StringSound(double frequency) : data(ceil(SR / frequency)) {
    try {
        while ( data.isEmpty() ) {
            data.enqueue(0);
        }
        num_of_tics = 0;
        if (num_of_tics < 0) {
            throw num_of_tics;
        }
    } catch (...) {
        std::cout << "Error - SS constructor frequency" << std::endl;
    }

}

StringSound::StringSound(std::vector<sf::Int16> init) : data(init.size() ) {
    try {
        for (std::vector<sf::Int16>::iterator it = init.begin(); it != init.end(); ++it) {
            data.enqueue(*it);
        }
    } catch (...) {
       std::cout << "Error - SS constructor vector" << std::endl;
    }
}

void StringSound::pluck() {
    try {
        while (!data.isEmpty()) {
            data.dequeue();
        }
        while (!data.isFull()) {
            data.enqueue((sf::Int16)(rand() & 0xffff));
        }
    } catch (...) {
        std::cout << "Error - pluck()" << std::endl;
    }
}

void StringSound::tic() {
    try {
        int16_t one = data.dequeue();
        int16_t two = data.peek();
        auto total = [](int16_t a, int16_t b) {
            return ((a + b) / 2.0 * .996);
//            return (0-((a + b) / 2.0 * .996));
        };  // Lambda expression
        data.enqueue(total(one, two));
    } catch (...) {
        std::cout << "Error - tic()" << std::endl;
    }
}

sf::Int16 StringSound::sample() {
    return data.peek();
}

int StringSound::time() {
    return num_of_tics++;
}
