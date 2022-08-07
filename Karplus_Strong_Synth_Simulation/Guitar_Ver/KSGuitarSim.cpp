#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <math.h>
#include <limits.h>

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>

#include "CircularBuffer.h"
#include "StringSound.h"

#define CONCERT_A 440.0
#define SAMPLES_PER_SEC 44100

std::vector<sf::Int16> makeSamplesFromString(StringSound gs) {
    std::vector<sf::Int16> samples;

    gs.pluck();
    int duration = 8;  // seconds
    int i;
    for (i= 0; i < (SAMPLES_PER_SEC * duration) ; i++) {
        gs.tic();
        samples.push_back(gs.sample());
    }

    return samples;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(300, 200), "Sean Ko - PS3b - Guitar");
    sf::Event event;
    double freq;
    unsigned long int key = 0; //NOLINT
    std::vector<std::vector<sf::Int16> > samples(37); //37

    std::vector <sf::Sound> sound(37);  //37
    std::vector <sf::SoundBuffer> buf(37); //37

    for (int i=0; i < 37; i++) {
        freq = CONCERT_A * pow(2.0, (i+4) / 12.0);  //12.0
        samples.at(i) = makeSamplesFromString(StringSound(freq));
        if (!buf.at(i).loadFromSamples(&(samples.at(i))[0],
                                       samples.at(i).size(), 2, SAMPLES_PER_SEC)) {
            throw
                    std::runtime_error("sf::SoundBuffer: failed to load from samples.");
        }
        (sound.at(i)).setBuffer(buf.at(i));
    }

    std::string keyboard = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::TextEntered:
                    key = keyboard.find(event.text.unicode);
                    if (key != std::string::npos) {
                        sound.at(key).play();
                    }
                    break;
                default:
                    break;
            }
            window.clear();
            window.display();
        }
    }
    return 0;
}
