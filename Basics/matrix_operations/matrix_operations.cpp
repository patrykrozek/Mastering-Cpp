#include <iostream>
#include <random>
#include <cmath>
using namespace std;

// Prototypy funkcji
int** matrix_creator_one(int, int);
void matrix_printer(int**, int, int);
int clear_matrix(int**, int);
int trace_of_a_square_matrix(int**, int, int);
int** transposition(int**, int, int);
int** reshape(int**, int, int, int, int);
int** del(int**, int, int, int, int);
int det(int**, int);

int main() {
    int r, c, r1, c1, rd, cd;
    cout << "Enter the size of the R x C matrix" << endl;
    cin >> r >> c;

    int** t = matrix_creator_one(r, c);
    matrix_printer(t, r, c);

    cout << endl << "Trace of a square matrix: " << trace_of_a_square_matrix(t, r, c) << endl;

    if (r == c) {
        int** t_transposed = transposition(t, r, c);
        cout << "=========== Transposed matrix ================" << endl;
        matrix_printer(t_transposed, r, c);
    }

    cout << "=========== Create reshaped matrix ================" << endl;
    cout << "Enter new size of the matrix - remember, that the amount of values must be the same" << endl;
    cout << "Enter number of rows: ";
    cin >> r1;
    cout << "Enter number of columns: ";
    cin >> c1;
    int** reshape_t = reshape(t, r, c, r1, c1);
    if (reshape_t != 0) {
        matrix_printer(reshape_t, r1, c1);
    }

    cout << "=========== Delete row and col in matrix ================" << endl;
    cout << "Enter row and column you want to delete" << endl;
    cout << "Enter number of rows: ";
    cin >> rd;
    cout << "Enter number of columns: ";
    cin >> cd;

    // Tworzymy now¹ macierz po usuniêciu wiersza i kolumny
    int** newMatrix = del(reshape_t, r1, c1, rd, cd);
    matrix_printer(newMatrix, r1 - 1, c1 - 1);

    cout << "=========== Determinant of the matrix ================" << endl;
    cout << "Determinant: " << det(newMatrix, r1 - 1) << endl;

    // Zwalnianie pamiêci
    clear_matrix(t, r);
    clear_matrix(newMatrix, r1 - 1);
    system("pause");
    return 0;
}

// Funkcja do tworzenia macierzy o wymiarach r x c z losowymi liczbami
int** matrix_creator_one(int r, int c) {
    int** t = new int* [r];
    random_device R;
    for (int i = 0; i < r; ++i) {
        t[i] = new int[c];
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            t[i][j] = R() % 101; // Losowanie liczb od 0 do 100
        }
    }
    return t;
}

// Funkcja do drukowania macierzy
void matrix_printer(int** t, int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << t[i][j] << '\t';
        }
        cout << endl;
    }
}

// Funkcja do obliczania œladu macierzy (tylko dla macierzy kwadratowych)
int trace_of_a_square_matrix(int** t, int r, int c) {
    int s = 0;
    for (int i = 0; i < min(r, c); ++i) {
        s += t[i][i];
    }
    return s;
}

// Funkcja do transponowania macierzy
int** transposition(int** t, int r, int c) {
    int** t_transposed = new int* [c];
    for (int i = 0; i < c; ++i) {
        t_transposed[i] = new int[r];
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            t_transposed[j][i] = t[i][j];
        }
    }
    return t_transposed;
}

// Funkcja do tworzenia przekszta³conej macierzy
int** reshape(int** t, int r, int c, int r1, int c1) {
    if (r * c != r1 * c1) {
        cout << "Number of elements is not the same" << endl;
        return nullptr;
    }
    int idx = 0;
    int** reshape_t = new int* [r1];
    for (int i = 0; i < r1; ++i) {
        reshape_t[i] = new int[c1];
    }

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            int row = idx / c1;
            int col = idx % c1;
            reshape_t[row][col] = t[i][j];
            idx++;
        }
    }
    return reshape_t;
}

// Funkcja do usuwania wiersza i kolumny
int** del(int** t, int r, int c, int rd, int cd) {
    int newRow = 0;
    int** td = new int* [r - 1];
    for (int i = 0; i < r - 1; ++i) {
        td[i] = new int[c - 1];
    }

    for (int i = 0; i < r; ++i) {
        if (i == rd) continue;
        int newCol = 0;
        for (int j = 0; j < c; ++j) {
            if (j == cd) continue;
            td[newRow][newCol] = t[i][j];
            newCol++;
        }
        newRow++;
    }
    return td;
}

// Funkcja obliczaj¹ca wyznacznik
int det(int** t, int n) {
    if (n == 1) {
        return t[0][0];
    }

    if (n == 2) {
        return t[0][0] * t[1][1] - t[0][1] * t[1][0];
    }

    int determinant = 0;
    for (int k = 0; k < n; ++k) {
        int** t1 = del(t, n, n, 0, k); // Tworzymy macierz mniejsz¹
        determinant += pow(-1, k) * t[0][k] * det(t1, n - 1);
        for (int i = 0; i < n - 1; ++i) {
            delete[] t1[i];
        }
        delete[] t1;
    }
    return determinant;
}

// Funkcja do zwalniania pamiêci
int clear_matrix(int** t, int r) {
    for (int i = 0; i < r; ++i) {
        delete[] t[i];
    }
    delete[] t;
    return 0;
}
