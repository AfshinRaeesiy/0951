#include <iostream>
using namespace std;

void drawRectangle(int length, int width) {
    for (int i = 0; i < length; i++) {
        cout << "=";
    }
    cout << endl;

    for (int i = 0; i < width - 2; i++) {
        cout << "|";
        for (int j = 0; j < length - 2; j++) {
            cout << " ";
        }
        cout << "|";
        cout << endl;
    }

    for (int i = 0; i < length; i++) {
        cout << "=";
    }
    cout << endl;
}

int main() {
    int length, width;

    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the width of the rectangle: ";
    cin >> width;

    if (length > 1 && width > 1) {
        drawRectangle(length, width);
    } else {
        cout << "Length and width must be greater than 1." << endl;
    }

    return 0;
}
