#ifndef GUITARSTRING_HPP_
#define GUITARSTRING_HPP_

#include <stdint.h>
#include <SFML/Audio.hpp>
#include <queue>
#include <vector>
#include "CircularBuffer.h"

class StringSound {
 public:
    explicit StringSound(double frequency);
    explicit StringSound(std::vector<sf::Int16> init);
    void pluck();
    void tic();
    sf::Int16 sample();
    int time();
 private:
    CircularBuffer data;
    int num_of_tics;
};

#endif  // GUITARSTRING_HPP_
