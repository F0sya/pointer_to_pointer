#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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

template<typename T>
T** addToMatrix(T** arr, int row, int col) {
    for (size_t i = 0; i < col; i++) {
        arr[row][i] = rand() % 10;
    }
    return arr;
}

int main()
{
    int max_col = 10;
    int max_row = 10;
    int col; cout << "Enter an amount of columns:"; cin >> col;
    int row; cout << "Enter an amount of rows:"; cin >> row;
    int** arr = createMatrix<int>(max_row, max_col);
    fillMatrix(arr, row, col);
    printMatrix(arr, row, col);
    cout << endl << "Matrix after adding new row:" << endl;
    arr = addToMatrix(arr, row, col);
    printMatrix(arr, row + 1, col);
    return 0;
}