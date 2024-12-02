/*
Tasks to do:
- creat 2d array with random no from defined scope - DONE
- calculate trace of the matrix - DONE
- calculate min value and show it's position DONE
- transposition - In progress
- calculate the determinant of the matrix
- reshape
- delete x row and column from the matrix
*/


int** matrix_creator(int, int,int,int);
void matrix_printer(int**, int, int);
int matrix_trace(int**, int, int);
void min_value(int**, int, int);
int** matrix_trans(int**, int, int);



#include <iostream>
#include <random>
using namespace std;


int main() {
	int r, c, top_limit = 50,down_limit=10;
	
	cout << "Enter the R x C size of the matrix: ";
	cin >> r>>c;
	int **matrix=matrix_creator(r, c,top_limit,down_limit);
	matrix_printer(matrix, r, c);
	cout <<"Trace of a matrix: " << matrix_trace(matrix, r, c)<<endl;
	min_value(matrix, r, c);
	int** c_matrix = matrix_trans(matrix, r, c);
	matrix_printer(c_matrix, c, r);
}

int** matrix_creator(int r, int c, int top_limit,int down_limit) {
	random_device R;
	int** matrix = new int* [r];
	for (int i = 0; i < r; ++i) {
		matrix[i] = new int[c];
	}
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			matrix[i][j] = R() % (top_limit - down_limit + 1) + down_limit;
		}
	}
	return matrix;
}

void matrix_printer(int** matrix, int r, int c) {
	cout << "======== MatrixPrinter ======"<<endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}
	cout << "====================="<<endl;
}


int matrix_trace(int** matrix, int r, int c) {
	int trace = 0;
	for (int i = 0; i < r && i < c;++i) {
		trace += matrix[i][i];
	}
	return trace;
}


void min_value(int** matrix, int r, int c) {
	int min = matrix[0][0];
	int pos_r = 0,pos_c=0;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (matrix[i][j] < min) {
				min = matrix[i][j];
				pos_r = i;
				pos_c = j;
			}
		}
	}
	cout << "Min value of the matrix: " << min << endl;
	cout << "Row: " << pos_r << endl;
	cout << "Column: " << pos_c << endl << endl;
}


int** matrix_trans(int** matrix, int c, int r) {
	int** c_matrix = new int* [r];
	for (int i = 0; i < r; ++i) {
		c_matrix[i] = new int[c];
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			c_matrix[i][j] = matrix[j][i];
		}
	}
	return c_matrix;
}