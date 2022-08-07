#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
#include <string>
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
istream& operator >> (istream& input, CelestialBody& p) {

    input >> (p.xCoordinate) >> (p.yCoordinate) >> (p.xVelocity)
          >> (p.yVelocity) >> (p.mass);
    return input;
}

double CelestialBody::getX_vel() const {
    return xVelocity;
}

double CelestialBody::getY_vel() const {
    return yVelocity;
}

double CelestialBody::getX_coor() const {
    return xCoordinate;
}

double CelestialBody::getY_coor() const {
    return yCoordinate;
}

double CelestialBody::getMass() const {
    return mass;
}

double CelestialBody::getGalaxy_radius() const {
    return galaxyRadius;
}

int CelestialBody::getWindow_size() const {
    return window_size;
}

void CelestialBody::setX_vel(double xVel) {
    xVelocity = xVel;
}

void CelestialBody::setY_vel(double yVel) {
    yVelocity = yVel;
}

void CelestialBody::setX_coor(double xCoor) {
    xCoordinate = xCoor;
}

void CelestialBody::setY_coor(double yCoor) {
    yCoordinate = yCoor;
}

void CelestialBody::setMass(double massAll) {
    mass = massAll;
}

void CelestialBody::setGalaxy_radius(double gRadius) {
    galaxyRadius = gRadius;
}

void CelestialBody::setWindow_size(int winSize) {
    window_size = winSize;
}

void CelestialBody::step(double seconds) {
    setX_coor(getX_coor() + getX_vel() * seconds);
    setY_coor(getY_coor() - getY_vel() * seconds);
}

void CelestialBody::iteration(const vector<shared_ptr<CelestialBody> > &galaxy, int planetCount, int index, double stepSeconds) {
    double xNetForce = 0;
    double yNetForce = 0;
    double gConstant = 6.67e-11;
    double xAcceleration, yAcceleration;
    // Calculates force
    for (int i = 0; i < planetCount; i++) {
        if (i != index) {
            double xDelta, yDelta, radius, force;
            xDelta = galaxy[i]->getX_coor() - getX_coor();
            yDelta = getY_coor() - galaxy[i]->getY_coor();
            radius = sqrt(xDelta * xDelta + yDelta * yDelta);
            force = ((getMass() * galaxy[i]->getMass() * gConstant) / (radius * radius));
            xNetForce += (xDelta / radius) * force;
            yNetForce += (yDelta / radius) * force;
        }
    }
    // Calculates acceleration
    xAcceleration = xNetForce / getMass();
    yAcceleration = yNetForce / getMass();
    // Calculates velocity
    setX_vel(getX_vel() + xAcceleration * stepSeconds);
    setY_vel(getY_vel() + yAcceleration * stepSeconds);
}


