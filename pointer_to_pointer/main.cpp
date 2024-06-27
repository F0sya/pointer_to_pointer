#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;

template<typename T>
T** createMatrix(int max_row, int max_col)
{
    T** arr = new T * [max_row];
    for (int i = 0; i < max_row; i++)
    {
        arr[i] = new T[max_col];
    }
    return arr;
}

template<typename T>
void fillMatrix(T** arr, int row, int col)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }
}

template<typename T>
void printMatrix(T** arr, int row, int col)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void addToMatrix(int** arr, int row, int col, int choice) {

    for (int i = 0; i < row; i++) {
        int* newRow = new int [col + 1];
        for (int j = 0, k = 0; j <= col; j++) {
            if (j == choice) {
                newRow[j] = rand() % 10;
            }
            else {
                newRow[j] = arr[i][k++];
            }
        }
        delete arr[i];
        arr[i] = newRow;
    }
}

int main()
{
    srand(time(0));
    int max_col = 10;
    int max_row = 10;
    int col; cout << "Enter an amount of columns:"; cin >> col;
    int row; cout << "Enter an amount of rows:"; cin >> row;
    int choice; cout << "Enter an index of line:"; cin >> choice;
    int** arr = createMatrix<int>(max_row, max_col);
    fillMatrix(arr, row, col);
    printMatrix(arr, row, col);
    cout << endl << "Matrix after appending col:" << endl;
    addToMatrix(arr, row, col, choice);
    printMatrix(arr, row, col + 1);

    delete[] arr;
    return 0;
}