#include <random>
#include <iostream>

using namespace std;


int* array_creator(int,int,int);
void array_printer(int*, int);
double avg(int*, int);

int main() {
	int n, top_limit = 100, down_limit = 15;
	cout << "Enter the n-size of the array: ";
	cin >> n;
	cout << endl;

	int* t = array_creator(n,top_limit,down_limit);
	array_printer(t, n);
	cout << "Average value of the array: "<<avg(t, n)<<endl;
}

int* array_creator(int n,int top_limit,int down_limit) {
	random_device R;
	int* t = new int[n];
	for (int i = 0; i < n; ++i) {
		t[i] = R() % (top_limit - down_limit + 1) + down_limit;
	}
	return t;
}


void array_printer(int* t, int n) {
	for (int i = 0; i < n; ++i) {
		cout << t[i] << '\t';
	}
	cout << endl;
}

double avg(int* t, int n) {
	double sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += t[i];
	}
	return sum / n;
}