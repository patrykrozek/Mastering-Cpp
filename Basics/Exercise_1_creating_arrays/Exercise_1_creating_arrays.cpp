#include <iostream>
using namespace std;

void print(int[], int); //Function, that prints whole array

int main() {
	const int n = 5; //Array has to have const size
	int t[n] = { 1,2,3,4,5 };
	cout <<"Address of the array: " << t << "\n"; //Address of the array
	print(t, n);
}

void print(int t[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << t[i] << ' ';
	}
}