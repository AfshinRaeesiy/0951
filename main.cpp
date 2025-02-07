#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

void Input(int matrix[MAX_SIZE][MAX_SIZE], int &rows, int &cols) {
    cout << "Enter number of rows and columns (max " << MAX_SIZE << "): ";
    cin >> rows >> cols;
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }
}

void Print(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    cout << "Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void ADD(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void Subtract(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void Multiply(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

bool Search(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int value) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == value) {
                cout << "Value " << value << " found at (" << i << ", " << j << ")\n";
                return true;
            }
        }
    }
    cout << "Value " << value << " not found.\n";
    return false;
}

void EditMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, int row, int col, int newValue) {
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        matrix[row][col] = newValue;
        cout << "Element at (" << row << ", " << col << ") updated to " << newValue << ".\n";
    } else {
        cout << "Invalid index!\n";
    }
}

void sumRows(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    cout << "Sum of each row:\n";
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
        cout << "Row " << i << ": " << sum << endl;
    }
}

void sumCols(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    cout << "Sum of each column:\n";
    for (int j = 0; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += matrix[i][j];
        }
        cout << "Column " << j << ": " << sum << endl;
    }
}

void SumMain(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += matrix[i][i];
    }
    cout << "Sum of main diagonal: " << sum << endl;
}

void countZeros(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) count++;
        }
    }
    cout << "Number of zero elements: " << count << endl;
}

void Identify(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    bool upperTriangular = true, lowerTriangular = true;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i > j && matrix[i][j] != 0) upperTriangular = false;
            if (i < j && matrix[i][j] != 0) lowerTriangular = false;
        }
    }

    if (upperTriangular) cout << "The matrix is upper triangular.\n";
    else if (lowerTriangular) cout << "The matrix is lower triangular.\n";
    else cout << "The matrix is neither upper nor lower triangular.\n";
}

void sortMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows * cols - 1; i++) {
        for (int j = 0; j < rows * cols - i - 1; j++) {
            int row1 = j / cols, col1 = j % cols;
            int row2 = (j + 1) / cols, col2 = (j + 1) % cols;

            if (matrix[row1][col1] > matrix[row2][col2]) {
                swap(matrix[row1][col1], matrix[row2][col2]);
            }
        }
    }
    cout << "Matrix sorted.\n";
}

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;


    cout << "Matrix 1:\n";
    Input(matrix1, rows1, cols1);


    cout << "Matrix 2:\n";
    Input(matrix2, rows2, cols2);


    Print(matrix1, rows1, cols1);
    Print(matrix2, rows2, cols2);


    if (rows1 == rows2 && cols1 == cols2) {
        ADD(matrix1, matrix2, result, rows1, cols1);
        cout << "Addition Result:\n";
        Print(result, rows1, cols1);


        Subtract(matrix1, matrix2, result, rows1, cols1);
        cout << "Subtraction Result:\n";
        Print(result, rows1, cols1);


        if (cols1 == rows2) {
            Multiply(matrix1, matrix2, result, rows1, cols1, cols2);
            cout << "Multiplication Result:\n";
            Print(result, rows1, cols2);
        } else {
            cout << "Cannot multiply matrices: incompatible dimensions.\n";
        }
    } else {
        cout << "Cannot add or subtract matrices: incompatible dimensions.\n";
    }


    int searchValue;
    cout << "Enter a value to search in Matrix 1: ";
    cin >> searchValue;
    Search(matrix1, rows1, cols1, searchValue);


    int editRow, editCol, newValue;
    cout << "Enter row and column to edit in Matrix 1: ";
    cin >> editRow >> editCol;
    cout << "Enter new value: ";
    cin >> newValue;
    EditMatrix(matrix1, rows1, cols1, editRow, editCol, newValue);


    sumRows(matrix1, rows1, cols1);
    sumCols(matrix1, rows1, cols1);


    SumMain(matrix1, min(rows1, cols1));


    countZeros(matrix1, rows1, cols1);


    Identify(matrix1, rows1, cols1);


    sortMatrix(matrix1, rows1, cols1);


    Print(matrix1, rows1, cols1);

    return 0;
}
