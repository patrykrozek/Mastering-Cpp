#include <iostream>
#include <random>
#include <typeinfo>
using namespace std;


void program_1();
void program_2();
void printer(int[],int);
void min(int[], int);
void max(int[], int);
double average(int[], int);
int display_menu();
//int& min_2(int[t], int);
//int& max_2(int[t], int);
int* array_creator(int, int, int);
int how_many_words(char[]);
int how_many_big_letters(char[]);
char* word_creator();
char* change_size_up(char[]);


int main() {
	while (true) {
		int p =display_menu();
		if (p == 0) {
			cout << "Exiting program! Good Bye!" << endl;
			break;
		}
	switch (p) {
	case 1: {
		program_1();
		break;
	}
	case 2: {
		program_2();
		break;
	}
	case 3: {
		int n, max_value, min_value;
		cout << "Hello, please enter the n-size array you want to make: ";
		cin >> n;
		cout << endl << "Enter the top limit: ";
		cin >> max_value;
		cout << endl << "Enter the down limit: ";
		cin >> min_value;
		int* array = array_creator(n, max_value, min_value);
		for (int i = 0; i < n; ++i) {
			cout << array[i] << '\t';
		}
		cout<<endl << "The average value of the array is: " << average(array, n) << endl;
		cout << '\n' << '\n';

		break;
	}
	case 4: {
		cout << "Hello, this is how many words program 1 ;) "<<'\n';
		char text[] = { "Ala has a cat\nOla has a dog" };
		cout << text << " <-- This text has: "<<how_many_words(text) << " words, and "<<how_many_big_letters(text)<<" big letters" << endl;
		break;
	}
	case 5: {
		char* text = word_creator();
		cout << text << " <-- This text has: " << how_many_words(text) << " words, and " << how_many_big_letters(text) << " big letters" << endl;
		
		char* text_up=change_size_up(text);
		cout << "Text with upper letters: " << text_up << endl;

		break;
	}
	
	}
	

	}
		
}

double average(int t[], int n) {
	double sum = 0;
	
	for (int i = 0; i < n; ++i) {
		sum = sum + t[i];
	}
	return sum / n;
}


char* change_size_up(char t[]) {
	int i = 0;
	while (t[i]) {
		
		if (t[i]>='a' && t[i]<='z') {
			t[i] = t[i] - 'a' + 'A';
		}
		++i;
	}
	return t;
}


char* word_creator() {
	cout << "Please insert the word, and finish with an enter: ";
	cin.ignore();
	char* sentence = new char[1];
	sentence[0] = '\0';
	int current_length = 0;
	

	while (true) {
		char ch;

		cin >> noskipws >> ch; 
		if (ch == '\n') {
			break;
		}
		char* temp = new char[current_length + 2];
		for (int i = 0; i < current_length; ++i) {
			temp[i] = sentence[i];

		}
		temp[current_length] = ch;        // Dodaj nowy znak
		temp[current_length + 1] = '\0'; // Dodaj zakoñczenie
		delete[] sentence;  // Usuñ star¹ tablicê
		sentence = temp;    // Zaktualizuj wskaŸnik
		++current_length;   // Zwiêksz d³ugoœæ

	}
	cout << "You entered: " << sentence << endl;
	return sentence;
}

int how_many_big_letters(char t[]) {
	int c = 0;
	int i = 0;
	while (t[i]) {
		if (t[i] >= 'A' && t[i] <= 'Z') {
			++c;
		}
		++i;
	}
	return c;
}

int how_many_words(char t[]) {
	int c = 1;
	int i = 1;
	while (t[i]) {
		if (t[i] == ' '|| t[i]=='\n') {
			++c;
		}
		++i;
	}
	return c;
}

int display_menu() {
	int p;
	cout << "==============================================" << endl;
	cout << "              PROGRAM MENU                    " << endl;
	cout << "==============================================" << endl;
	cout << "1. Simple n-size array with random numbers" << endl;
	cout << "2. Simple n-size array with user range numbers" << endl;
	cout << "3. Array creator and  with user range numbers" << endl;
	cout << "4. How many words?" << endl;
	cout << "5. Change the letters size" << endl;


	cout << "0. Exit" << endl;
	cout << "==============================================" << endl;
	cout << endl << "Your choice: ";
	cin >> p;
	cout << endl;
	return p;
}


int *array_creator(int n, int max_value, int min_value) {
	random_device R;
	int* t = new int[n];
	for (int i = 0; i < n; ++i) {
		t[i] = R() % (max_value - min_value + 1) + min_value;
	}
	return t;
	
}


void min(int t[], int n) {
	
	int min = t[0], position;
	for (int i = 1; i < n;++i) {
		if (t[i] < min) {
			min = t[i];
			position = i+1;
		}
	}
	cout << "Min value of the array is on: "<< position << " place, and it's: " << min << endl;
}

void max(int t[], int n) {
	
	int max = t[0],position;
	for (int i = 1; i < n; ++i) {
		if (t[i] > max) {
			max = t[i];
			position = i+1;
		}
	}
	cout << "Max value of the array is on: " << position << " place, and it's: " << max << endl;
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
	min(t, n);
	max(t, n);
}


void printer(int t[],int n) {
	for (int i = 0; i < n; ++i) {
		cout << t[i] << '\t';
	}
	cout << endl<<endl;
}