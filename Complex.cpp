#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    float real;
    float imag;

public:

    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& obj) const {
        return Complex(real + obj.real, imag + obj.imag);
    }

    Complex operator-(const Complex& obj) const {
        return Complex(real - obj.real, imag - obj.imag);
    }

    Complex operator*(const Complex& obj) const {
        return Complex(
            real * obj.real - imag * obj.imag,
            real * obj.imag + imag * obj.real
        );
    }

    Complex operator/(const Complex& obj) const {
        float denominator = obj.real * obj.real + obj.imag * obj.imag;
        if (denominator == 0) {
            cerr << "Error: Division by zero!" << endl;
            return Complex();
        }
        return Complex(
            (real * obj.real + imag * obj.imag) / denominator,
            (imag * obj.real - real * obj.imag) / denominator
        );
    }

    Complex operator*(float scalar) const {
        return Complex(real * scalar, imag * scalar);
    }

    Complex operator/(float scalar) const {
        if (scalar == 0) {
            cerr << "Error: Division by zero!" << endl;
            return Complex();
        }
        return Complex(real / scalar, imag / scalar);
    }

    Complex& operator+=(const Complex& obj) {
        real += obj.real;
        imag += obj.imag;
        return *this;
    }

    Complex& operator-=(const Complex& obj) {
        real -= obj.real;
        imag -= obj.imag;
        return *this;
    }

    Complex& operator*=(const Complex& obj) {
        *this = *this * obj;
        return *this;
    }

    Complex& operator/=(const Complex& obj) {
        *this = *this / obj;
        return *this;
    }

    Complex operator-() const {
        return Complex(-real, -imag);
    }

    bool operator==(const Complex& obj) const {
        return real == obj.real && imag == obj.imag;
    }

    bool operator!=(const Complex& obj) const {
        return !(*this == obj);
    }

    float magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    Complex conjugate() const {
        return Complex(real, -imag);
    }

    // Friend functions for I/O and scalar multiplication
    friend ostream& operator<<(ostream& out, const Complex& f);
    friend istream& operator>>(istream& in, Complex& f);
    friend Complex operator*(float scalar, const Complex& f);
};

ostream& operator<<(ostream& out, const Complex& f) {
    out << f.real;
    if (f.imag >= 0)
        out << " + " << c.imag << "i";
    else
        out << " - " << -c.imag << "i";
    return out;
}

istream& operator>>(istream& in, Complex& f) {
    cout << "Enter real part: ";
    in >> f.real;
    cout << "Enter imaginary part: ";
    in >> f.imag;
    return in;
}

Complex operator*(float scalar, const Complex& f) {
    return f * scalar;
}

int main() {
    Complex f1(1, 5);
    Complex f2(3, -4);

    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;

    Complex f3 = f1 + f2;
    cout << "f1 + f2 = " << f3 << endl;

    Complex f4 = f1 - f2;
    cout << "f1 - f2 = " << f4 << endl;

    Complex f5 = f1 * f2;
    cout << "f1 * f2 = " << f5 << endl;

    Complex f6 = f1 / f2;
    cout << "f1 / f2 = " << f6 << endl;

    Complex f7 = 2.5f * f1;
    cout << "2.5 * f1 = " << f7 << endl;

    Complex f8 = f1 / 2;
    cout << "f1 / 2 = " << f8 << endl;

    cout << "Magnitude of f1: " << f1.magnitude() << endl;
    cout << "Conjugate of f1: " << f1.conjugate() << endl;

    cout << "f1 == f2? " << (f1 == f2 ? "Yes" : "No") << endl;
    cout << "f1 != f2? " << (f1 != f2 ? "Yes" : "No") << endl;

    Complex f9;
    cin >> f9;
    cout << "You entered: " << f9 << endl;

    return 0;
}
