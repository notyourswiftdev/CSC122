#include <iostream>
#include <cmath>

using namespace std;

class Sphere {
private:
    double radius;

public:
    Sphere(double r) {
        radius = r;
    }

    double getRadius() {
        return radius;
    }

    void setRadius(double r) {
        radius = r;
    }

    double getSurfaceArea() {
        return 4 * M_PI * pow(radius, 2);
    }

    double getVolume() {
        return (4.0 / 3.0) * M_PI * pow(radius, 3);
    }
};

class Planet : public Sphere {
private:
    double mass;

public:
    Planet(double r, double m) : Sphere(r) {
        mass = m;
    }

    double getMass() {
        return mass;
    }

    void setMass(double m) {
        mass = m;
    }

    double getDensity() {
        return mass / getVolume();
    }

    double getGravity() {
        const double G = 6.67430e-11; // gravitational constant
        return G * mass / pow(getRadius(), 2);
    }
};

int main() {
    double radius, mass;
    cout << "Enter radius of planet: ";
    cin >> radius;
    cout << "Enter mass of planet: ";
    cin >> mass;

    Planet planet(radius, mass);
    cout << "Surface area: " << planet.getSurfaceArea() << endl;
    cout << "Density: " << planet.getDensity() << endl;
    cout << "Acceleration due to gravity at the surface: " << planet.getGravity() << endl;

    return 0;
}
