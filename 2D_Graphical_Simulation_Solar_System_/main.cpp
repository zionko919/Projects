#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <string>
#include <sstream>
#include <cstdlib>
#include "nbody.h"

using namespace std;
using namespace sf;

namespace patchString {
    template <typename T> string to_string(const T& num) {
        ostringstream  myString;
        myString << num;
        return myString.str();
    }
}

int main(int argc, char* argv[]) {
    if(argc != 3) {
        cout << "Error! Invalid argument numbers" << endl;
        exit(1);
    }
    int planetNum;
    int window_size = 500;  // just set mine to 500
    float radius;
    double timer = 0;
    double maxSeconds = atof(argv[1]);
    double stepSeconds = atof(argv[2]);
    cin >> planetNum >> radius;    // grab planet number and radius from the .txt file
//    vector<shared_ptr<CelestialBody>> solarSystem;
    Universe ourSystem; // creating an object from Universe class
    // cout << planetNum;
    // cout << radius;
    // loop to access CelestialBody class constructors and values to set up elements for SFML things.
    for(int i = 0; i < planetNum; i++)
    {
//        CelestialBody *newPlanet = new CelestialBody(window_size, radius);
//        shared_ptr<CelestialBody> newPlanet = new CelestialBody(window_size, radius);
        // using smart pointers to create an object for planets.
        shared_ptr<CelestialBody> newPlanet = make_shared<CelestialBody>(CelestialBody(window_size, radius));
        cin >> *newPlanet;  // getting planet information from .txt file
        string name;
        getline(cin, name);
        newPlanet->setPlanetName(name); //setting planets names.
        newPlanet->initialize();    //initializing my image, texture, sprites and so on.
//        solarSystem.push_back(newPlanet);
        ourSystem.universe.push_back(newPlanet);    // pushing back planet into the vector in universe class.
    }
//     for(int i = 0; i < planetNum; i++)
//     {
//     	solarSystem[i]->printfilename();
//     }

    // SFML stuff that we have been doing before.
    RenderWindow window( VideoMode(window_size, window_size), "PS2b: The Solar System");
    window.setFramerateLimit(60);

    // These are for background images. basic SFML stuff
    Image backgroundImage;
    if(!backgroundImage.loadFromFile("starfield.jpg"))
    {
        exit(-1);
    }
    Texture backgroundTexture;
    backgroundTexture.loadFromImage(backgroundImage);
    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    // Setting up the background Music
    Music music;
    if(!music.openFromFile("2001.wav")) {
        cout << "Error! Could not load the music file" << endl;
    }
    music.setLoop(true);
    music.play();


    // Setting up Font to show time elapsed (timer).
    Font myFont;
    if(!(myFont.loadFromFile("arial.ttf"))) {
        cout << "Error! Could not load the font file" << endl;
        return -1;
    }
    Text myText;
    myText.setFont(myFont);
    myText.setCharacterSize(24);
    myText.setFillColor(Color::White);

    while (window.isOpen() && timer <= maxSeconds)
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(backgroundSprite);  // draws the background
        for(int i = 0; i < planetNum; i++) {
            ourSystem.universe[i]->iteration(ourSystem.universe, planetNum, i, stepSeconds);
            ourSystem.universe[i]->step(stepSeconds);
        }
        for(int i = 0; i < planetNum; i++)
        {
//            solarSystem[i]->relocatePosition();
//            window.draw(*solarSystem[i]);
            ourSystem.universe[i]->relocatePosition();  // setting the position for the planet from the Universe class
            window.draw(*ourSystem.universe[i]);    // drawing planet
        }   // go through loop for each planets.
        timer += stepSeconds;
        myText.setString(patchString::to_string(timer));
        window.draw(myText);
        window.display();
    }

    // output the final state in correct format;
    cout.precision(1);
    cout << fixed << maxSeconds << " " << stepSeconds << endl;
    return 0;
}
