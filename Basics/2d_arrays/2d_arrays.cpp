/*
Tasks to do:
- creat 2d array with random no from defined scope - DONE
- calculate trace of the matrix - DONE
- calculate min value and show it's position DONE
- transposition - DONE
- reshape - DONE
- delete x row and column from the matrix -DONE

============== UNDONE ==============
- calculate the determinant of the matrix
*/


int** matrix_creator(int, int,int,int);
void matrix_printer(int**, int, int);
int matrix_trace(int**, int, int);
void min_value(int**, int, int);
int** matrix_trans(int**, int, int);
int** matrix_reshape(int**, int, int,int,int);
int** matrix_del_row_col(int**, int, int,int,int);



#include <iostream>
#include <random>
using namespace std;


int main() {
	int r, c, top_limit = 50,down_limit=10,nr,nc,dr,dc;
	
	cout << "Enter the R x C size of the matrix: ";
	cin >> r>>c;
	int **matrix=matrix_creator(r, c,top_limit,down_limit);
	matrix_printer(matrix, r, c);
	cout <<"Trace of a matrix: " << matrix_trace(matrix, r, c)<<endl;
	min_value(matrix, r, c);
	int** c_matrix = matrix_trans(matrix, r, c);
	matrix_printer(c_matrix, c, r);
	cout << "Enter newR and newC size of the matrix"<<endl;
	cin >> nr >> nc;
	if (r * c != nr * nc) {
		cout << "Wrong sum of items in new matrix";
	}
	//else if (r==c) {
	//	cout << "Determinant of the matrix: " << matrix_del_row_col(matrix, r, c);
	//}
	else {
	int** r_matrix = matrix_reshape(matrix, r, c,nr,nc);
	matrix_printer(r_matrix, nr, nc);
	}
	cout << "Enter no. of row and column, you want to delete"<<endl;
	cin >> dr >> dc;
	int** new_matrix = matrix_del_row_col(matrix, r, c,dr,dc);
	matrix_printer(new_matrix, r-1, c-1);
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

int** matrix_reshape(int** matrix, int r, int c,int nr,int nc) {
	
	int** r_matrix = new int* [nr];
	for (int i = 0; i < nr; ++i) {
		r_matrix[i] = new int [nc];
	}
	for (int i = 0; i < r * c; ++i) {
		//Maping old values
		int old_row = i / c;
		int old_col = i % c;
		
		//Maping new values
		int new_row = i / nc;
		int new_col = i % nc;

		r_matrix[new_row][new_col] = matrix[old_row][old_col];
	}
	return r_matrix;
}

int** matrix_del_row_col(int** matrix, int r, int c,int dr,int dc) {
	int** new_matrix = new int* [r-1];
	for (int i = 0; i < r - 1; ++i) {
		new_matrix[i] = new int[c-1];
	}

	int ni = 0;
	for (int i = 0; i < r; ++i) {
		if (i == dr)continue;
		int nj = 0;
		for (int j = 0; j < c; ++j) {
			if (j == dc)continue;
			new_matrix[ni][nj] = matrix[i][j];
			++nj;
		}
		++ni;
	}

	return new_matrix;

}