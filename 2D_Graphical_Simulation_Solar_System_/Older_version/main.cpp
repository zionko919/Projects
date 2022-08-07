
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include "nbody.h"

using namespace std;
using namespace sf;

int main(int argc, char* argv[]) {
    int planetNum;
    int window_size = 500;  // just set mine to 500
    float radius;
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
    RenderWindow window( VideoMode(window_size, window_size), "PS2a: The Solar System");

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

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(backgroundSprite);  // draws the background
        for(int i = 0; i < planetNum; i++)
        {
//            solarSystem[i]->relocatePosition();
//            window.draw(*solarSystem[i]);
            ourSystem.universe[i]->relocatePosition();  // setting the position for the planet from the Universe class
            window.draw(*ourSystem.universe[i]);    // drawing planet
        }   // go through loop for each planets.
        window.display();
    }
    return 0;
}
