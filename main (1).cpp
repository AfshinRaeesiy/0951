#include <iostream>
#include <string>
using namespace std;

struct Planet {
    string name;
    string type;
    float temperature;
    float radius;
    int moons;
};

int main() {
    Planet planets[8];

    planets[0] = {"Mercury", "Rocky", 430.0, 2439.7, 0};
    planets[1] = {"Venus", "Rocky", 462.0, 6051.8, 0};
    planets[2] = {"Earth", "Rocky", 15.0, 6371.0, 1};
    planets[3] = {"Mars", "Rocky", -63.0, 3389.5, 2};
    planets[4] = {"Jupiter", "Gas", -108.0, 69911.0, 79};
    planets[5] = {"Saturn", "Gas", -139.0, 58232.0, 83};
    planets[6] = {"Uranus", "Gas", -197.0, 25362.0, 27};
    planets[7] = {"Neptune", "Gas", -201.0, 24622.0, 14};


    cout << "Planets in the Solar System:\n";
    for (int i = 0; i < 8; i++) {
        cout << "Name: " << planets[i].name << endl;
        cout << "Type: " << planets[i].type << endl;
        cout << "Temperature: " << planets[i].temperature << " °C" << endl;
        cout << "Radius: " << planets[i].radius << " km" << endl;
        cout << "Number of Moons: " << planets[i].moons << endl;
        cout << "------------------------\n";
    }

    return 0;
}
