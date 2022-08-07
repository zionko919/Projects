
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "nbody.h"

using namespace std;
using namespace sf;

// Constructor to save window size and radius.
CelestialBody::CelestialBody(int winSize, float systemRadius) {
    window_size = winSize;
    galaxyRadius = systemRadius;
}

// Constructor to draw my objects.
void CelestialBody::draw(RenderTarget &target, RenderStates state ) const {
    target.draw(celestial_body, state);
}

// Constructor to print my file names that I used to check what I am doing
void CelestialBody::printfilename () const {
    cout << fileName << std::endl;
}

// Constructor to set my planet names
void CelestialBody::setPlanetName(std::string s){
    string::iterator end_pos = remove(s.begin(), s.end(), ' ');
    s.erase(end_pos, s.end());
    fileName = s;
}

// constructor to initialize then to relocate position.
// scaling the position to a workable value since the original value is too big
// divding those texture numbers to radius to center the origins.
void CelestialBody::initialize() {
    if (!texture.loadFromFile(fileName))
    {
        cout << "Error! Cannot load file." << endl;
        exit(1);
    }
    celestial_body.setTexture(texture);
    celestial_body.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    // cout<<"wow";
}

void CelestialBody::relocatePosition() {
    float center = window_size / 2;
    float x = xCoordinate / galaxyRadius * center + center;
    float y = yCoordinate / galaxyRadius * center + center;
    celestial_body.setPosition(x,y);
}

// just overloading >> operator to grabe values quickly.
istream& operator >> (istream& in, CelestialBody& p) {

    in >> (p.xCoordinate) >> (p.yCoordinate) >> (p.xVelocity)
       >> (p.yVelocity) >> (p.mass);
    return in;
}

