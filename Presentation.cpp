#include <iostream>

using namespace std;

int main() {
    int Size;
    cout << "Enter the presentation size: ";
    cin >> Size;
    int arr[Size];
    cout << "please" << Size << " enter presentation element:\n";
    for (int i = 0; i < Size; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < Size - 1; i++) {
        for (int j = 0; j < Size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    double sum = 0;
    for (int i = 0; i < Size; i++) {
        sum += arr[i];
    }
    double average = sum / Size;

    cout << "Presentation after sorting: ";
    for (int i = 0; i < Size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "average presentation: " << average << endl;

    return 0;
}
