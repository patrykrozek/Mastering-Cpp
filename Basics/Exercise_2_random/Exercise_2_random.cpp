#include <iostream>
#include <random>
using namespace std;


void program_1();
void program_2();
void printer(int[],int);


int main() {
	while (true) {
		int p;
		cout << "Which program do you want to launch: " << '\n' << "1. Simple n-size array with random numbers" << '\n' <<"2. Simple n-size array with user range numbers" <<"Enter 0 to exit" << endl;
		cout << "Your choice: ";
		cin >> p;
		cout << endl;

		if (p == 0) {
			cout << "Exiting program! Good Bye!" << endl;
			break;
		}
	switch (p) {
	case 1:
		program_1();
		break;
	case 2:
		program_2();
		break;
	}

	}
		
}

void program_1() {
	int n;
	random_device R;
	cout << "Hello, this is program, that makes n-size array filled with random module numbers. Please enter n size of the array you want to make: ";
	cin >> n;
	int* t = new int[n];
	
	for (int i = 0; i < n;++i) {
		t[i] = R();
	}

	printer(t, n);
}
void program_2() {
	int n,ul,ll;
	random_device R;
	cout << "Hello, this is program, that makes n-size array filled with numbers from the range specified by the user. Please enter n size of the array you want to make: ";
	cin >> n;
	cout <<endl<< "Specify the upper limit: ";
	cin >> ul;
	cout << endl << "Specify the lower limit: ";
	cin >> ll;
	cout << endl;

	int* t = new int[n];

	for (int i = 0; i < n; ++i) {
		t[i] = R() % (ul - ll + 1) + ll;
	}

	printer(t, n);
}


void printer(int t[],int n) {
	for (int i = 0; i < n; ++i) {
		cout << t[i] << '\t';
	}
	cout << endl<<endl;
}