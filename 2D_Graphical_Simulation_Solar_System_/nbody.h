#ifndef NBODY_H
#define NBODY_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
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
    double getX_vel() const;
    double getY_vel() const;
    double getX_coor() const;
    double getY_coor() const;
    double getMass() const;
    double getGalaxy_radius() const;
    int getWindow_size() const;
    void setX_vel(double xVel);
    void setY_vel(double yVel);
    void setX_coor(double xCoor);
    void setY_coor(double yCoor);
    void setMass(double massAll);
    void setGalaxy_radius(double gRadius);
    void setWindow_size(int winSize);
    void step(double seconds);
    void iteration(const vector<shared_ptr<CelestialBody> > &galaxy, int planetCount, int index, double stepSeconds);
    friend istream& operator >> (istream& input, CelestialBody& p);
private:
    Texture texture;
    Sprite celestial_body;
    int window_size;
    double  xCoordinate, yCoordinate, xVelocity, yVelocity, mass, galaxyRadius;
    string fileName;
    virtual void draw(RenderTarget &target, RenderStates state ) const;
};

//Universe class (nbody.cpp has their information)
class Universe {
public:
    vector<shared_ptr<CelestialBody> > universe;
    void step(double seconds);
    void iteration(const vector<shared_ptr<CelestialBody> > &galaxy, int planetCount, int index, double stepSeconds);
};


#endif