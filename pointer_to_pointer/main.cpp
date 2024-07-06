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

void moveRows(int** array, int rows, int cols, int moves, int choice) {
	int* temp = new int[cols];
	moves = moves % cols;

	for (int i = 0; i < rows; ++i) {
		if (choice == 1) {
			for (int j = 0; j < moves; ++j) {
				temp[j] = array[i][j];
			}
			for (int j = moves; j < cols; ++j) {
				array[i][j - moves] = array[i][j];
			}
			for (int j = 0; j < moves; ++j) {
				array[i][cols - moves + j] = temp[j];
			}
		}
		else {
			for (int j = 0; j < moves; ++j) {
				temp[j] = array[i][cols - moves + j];
			}
			for (int j = cols - 1; j >= moves; --j) {
				array[i][j] = array[i][j - moves];
			}
			for (int j = 0; j < moves; ++j) {
				array[i][j] = temp[j];
			}
		}
	}

	delete[] temp;
}

void moveColumns(int** array, int rows, int cols, int moves, int choice) {
	int* temp = new int[rows];
	moves = moves % rows;

	for (int j = 0; j < cols; ++j) {
		if (choice == 1) {
			for (int i = 0; i < moves; ++i) {
				temp[i] = array[i][j];
			}
			for (int i = moves; i < rows; ++i) {
				array[i - moves][j] = array[i][j];
			}
			for (int i = 0; i < moves; ++i) {
				array[rows - moves + i][j] = temp[i];
			}
		}
		else {
			for (int i = 0; i < moves; ++i) {
				temp[i] = array[rows - moves + i][j];
			}
			for (int i = rows - 1; i >= moves; --i) {
				array[i][j] = array[i - moves][j];
			}
			for (int i = 0; i < moves; ++i) {
				array[i][j] = temp[i];
			}
		}
	}

	delete[] temp;
}

int main()
{
    srand(time(0));
    int max_col = 10;
    int max_row = 10;
    int col; cout << "Enter an amount of columns:"; cin >> col;
    int row; cout << "Enter an amount of rows:"; cin >> row;
    int moves; cout << "Enter an amount of moves:"; cin >> moves;
	cout << endl;
    int** arr = createMatrix<int>(max_row, max_col);
    fillMatrix(arr, row, col);
    printMatrix(arr, row, col);

	int choice_direction;  cout << "\nMove rows(1) or columns(2)?"; cin >> choice_direction;
	
	if (choice_direction == 1) {
		int second_choice_direction; cout << "Left(1) or right(2)"; cin >> second_choice_direction;
		moveRows(arr, row, col, moves, second_choice_direction);
	}
	else if (choice_direction == 2) {
		int second_choice_direction; cout << "Up(1) or Down(2)"; cin >> second_choice_direction;
		moveColumns(arr, row, col, moves, second_choice_direction);
	}
	else {
		cout << "Wrong input!" << endl;
	}

	cout << "\nMatrix after changing:" << endl;
	printMatrix(arr, row, col);
	cout << endl;
    delete[] arr;
    return 0;
}