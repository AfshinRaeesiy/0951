#include <iostream>
using namespace std;
class Shape{
protected:
    string color;
    string pattern;
public:
    Shape(string c,string p)
    {
        this->color=c;
        this->pattern=p;
    }
    void Display()
    {
        cout<<"the color of shape= "<<color<<" the pattern="<<pattern<<endl;
    }
};

class Circle:public Shape{
private:
    float radius;
public:
    Circle(float r,string c1, string p1):Shape(c1,p1){
        this->radius=r;
    }
//    void Display() //Ctrl+Shift+C
//    {
//        cout<<"the radius of circle= "<<this->radius<<"the color = "<<color<<" the pattern="<<pattern<<endl;
//    }
};

int main()
{
    Shape s1("Blue","dotdot");
    Circle c1(2.5,"Yellow","LineLine");
    s1.Display();
    c1.Display();

    return 0;
}
