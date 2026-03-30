#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int SIZE = 4;

class Matrix {
private:
    int data[SIZE][SIZE];

public:
    void readFromFile(ifstream &file) {
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                file >> data[i][j];
    }

    void display() const {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++)
                cout << setw(4) << data[i][j];
            cout << endl;
        }
    }

    Matrix operator+(const Matrix &other) const {
        Matrix result;
        for (int a = 0; a < SIZE; a++)
            for (int b = 0; b < SIZE; b++)
                result.data[a][b] = data[a][b] + other.data[a][b];
        return result;
    }

    Matrix operator*(const Matrix &other) const {
        Matrix result;
        for (int x = 0; x < SIZE; x++)
            for (int y = 0; y < SIZE; y++) {
                result.data[x][y] = 0;
                for (int z = 0; k < SIZE; z++)
                    result.data[x][y] += data[x][z] * other.data[z][y];
            }
        return result;
    }

    int sumOfDiagonals() const {
        int sum = 0;
        for (int i = 0; i < SIZE; i++) {
            sum += data[i][i];                 
            sum += data[i][SIZE - 1 - i];      
        }
        return sum;
    }

    void swapRows(int r1, int r2) {
        if (r1 < 0 || r1 >= SIZE || r2 < 0 || r2 >= SIZE) {
            cout << "Invalid row indices.\n";
            return;
        }
        for (int j = 0; j < SIZE; j++) {
            int temp = data[r1][j];
            data[r1][j] = data[r2][j];
            data[r2][j] = temp;
        }
    }
};

int main() {
    string filePath = "input.txt";  
    ifstream file(filePath);

    if (!file.is_open()) {
        cout << "Failed to open file: " << filePath << endl;
        return 1;
    }

    int num;
    file >> num;  
    if (num != SIZE) {
        cout << "Error: File size does not match SIZE = " << SIZE << endl;
        return 1;
    }

    Matrix mat1, mat2;

    mat1.readFromFile(file);
    mat2.readFromFile(file);

    file.close(); 

    cout << "Matrix 1:\n";
    mat1.display();

    cout << "\nMatrix 2:\n";
    mat2.display();

    Matrix sum = mat1 + mat2;
    cout << "\nSum of matrices:\n";
    sum.display();

    Matrix product = mat1 * mat2;
    cout << "\nProduct of matrices:\n";
    product.display();

    cout << "\nSum of diagonals of Matrix 1: "
         << mat1.sumOfDiagonals() << endl;

    mat1.swapRows(0, 2);
    cout << "\nMatrix 1 after swapping rows 0 and 2:\n";
    mat1.display();

    return 0;
}
