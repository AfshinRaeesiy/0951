#include <iostream>
#include <string>
using namespace std ;
class myCar {
public:
    myCar(string color, int year, int speed) : carColor(color), carYear(year), carSpeed(speed) {}

    myCar operator++(int) {
        myCar temp = *this;
        carSpeed++;
        return temp;
    }

    void displayInfo() const {
        cout << "CarColor: " << carColor << endl;
        cout << "CarYear: " << carYear << endl;
        cout << "CarSpeed: " << carSpeed << endl;
    }

private:
    string carColor;
    int carYear;
    int carSpeed;
};

int main() {
    myCar myFirstCar("Blue", 2024, 50);
    myCar previousState = myFirstCar++;

    cout << "situation before increase:" << endl;
    previousState.displayInfo();

    cout << "\nstatus after increase:" << endl;
    myFirstCar.displayInfo();

    return 0;
}
