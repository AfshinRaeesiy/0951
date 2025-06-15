#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    string color;
    string pattern;
public:
    Shape(string c, string p) {
        color = c;
        pattern = p;
    }

    void Display() {
        cout << "color: " << color << "، pattern: " << pattern << endl;
    }

    float Mohit() {
        cout << "Mohit not defined!" << endl;
        return 0;
    }

    float Masahat() {
        cout << "Masahat not defined!" << endl;
        return 0;
    }
};

class Circle : public Shape {
private:
    float radius;
public:
    Circle(float r, string c, string p) : Shape(c, p) {
        radius = r;
    }

    float Mohit() {
        return 2 * 3.14 * radius;
    }

    float Masahat() {
        return 3.14 * radius * radius;
    }

    void Display() {
        Shape::Display();
        cout << "circle" << endl;
        cout << "shoa: " << radius << endl;
        cout << "mohit: " << Mohit() << endl;
        cout << "masahat: " << Masahat() << endl;
    }
};

class Rectangle : public Shape {
private:
    float length;
    float width;
public:
    Rectangle(float l, float w, string c, string p) : Shape(c, p) {
        length = l;
        width = w;
    }

    float Mohit() {
        return 2 * (length + width);
    }

    float Masahat() {
        return length * width;
    }

    void Display() {
        Shape::Display();
        cout << "Rectangle:" << endl;
        cout << "tul: " << length << " arz:" << width << endl;
        cout << "mohit: " << Mohit() << endl;
        cout << "masahat: " << Masahat() << endl;
    }
};

class Triangle : public Shape {
private:
    float side1, side2, side3;
public:
    Triangle(float s1, float s2, float s3, string c, string p) : Shape(c, p) {
        side1 = s1;
        side2 = s2;
        side3 = s3;
    }

    float Mohit() {
        return side1 + side2 + side3;
    }

    float Masahat() {
        float s = Mohit() / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    void Display() {
        Shape::Display();
        cout << "Triangle" << endl;
        cout << "azla: " << side1 << ", " << side2 << ", " << side3 << endl;
        cout << "mohit: " << Mohit() << endl;
        cout << "masahat: " << Masahat() << endl;
    }
};

int main() {
    cout << "<Circle>" << endl;
    Circle myCircle(5.0, "gharmaz" , "noghteh i");
    myCircle.Display();

    cout << "\n<Rectangle>" << endl;
    Rectangle myRect(4.0, 6.0, "abi" , "khati");
    myRect.Display();

    cout << "\n<Triangle>" << endl;
    Triangle myTri(3.0, 4.0, 5.0, "sabz" , "rah rah");
    myTri.Display();

    return 0;
}
