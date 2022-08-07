// Zion "Sean" Ko
// 09-29-20
// Computing IV

#ifndef NBODY_H
#define NBODY_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <memory>

using namespace std;
using namespace sf;
// Celestial body class. (nody.cpp has the information)
class CelestialBody : public sf::Drawable {
public:
    CelestialBody(int winSize, float systemRadius);
    void printfilename() const;
    void setPlanetName(std::string s);
    void initialize();
    void relocatePosition();
    friend istream& operator >> (istream& in, CelestialBody& p);
private:
    Texture texture;
    Sprite celestial_body;
    int window_size;
    float  xCoordinate, yCoordinate, xVelocity, yVelocity, mass, galaxyRadius;
    string fileName;
    virtual void draw(RenderTarget &target, RenderStates state ) const;
};

//Universe class (nbody.cpp has their information)
class Universe {
public:
    vector<shared_ptr<CelestialBody>> universe;
};


#endif