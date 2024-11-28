#include <iostream>
#include<typeinfo>

using namespace std;

char* word_creator();
char* encryptor(char[]);
char* decryptor(char[]);


void main(){
	while (true) {
		int p;
		cout << "===========================================" << endl;
		cout << "Hello, this is the Caesar cipher programm - choose, what do you want to do: " << endl;
		cout << "0.Close the programm" << endl;
		cout << "1.Encrypt text" << endl;
		cout << "2.Decrypt text" << endl << endl;
		cout << "Your choice: ";
		cin >> p;

		if (p == 0) {
			cout << "Exiting programm! Good bye! ";
			break;
		}
		switch (p) {
		case 1: {

			cout << "Enter text you want to encrypt: ";
			char* sentence = word_creator();
			cout << "Encripted text: " << encryptor(sentence) << endl;
			break;
		}
		case 2: {

			cout << "Enter text you want to decrypt: ";
			char* sentence = word_creator();
			cout << "Decripted text: " << decryptor(sentence) << endl;
			break;
		}
		}

	}
}

char* word_creator() {
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
		temp[current_length] = ch; 
		temp[current_length + 1] = '\0';
		delete[]sentence; //Usun stara tablice
		sentence = temp;
		++current_length; //Zwiêksz d³ugosc
	}
	cout << "You entered: " << sentence << endl;
	return sentence;
}

char* encryptor(char t[]) {
	int shift = 3;
	int length = 0;
	while (t[length] != '\0') {
		++length;
	}

	char* encrypted_sentence = new char[length+1];

	for (int i = 0; i < length; ++i) {
		encrypted_sentence[i] = t[i] + shift;

	}
	encrypted_sentence[length] = '\0';  // Dodaj znak koñca ci¹gu
	return encrypted_sentence;
}


char* decryptor(char t[]) {
	int shift = 3;
	int length = 0;
	while (t[length] != '\0') {
		++length;
	}
	char* encrypted_sentence = new char[length + 1];
	for (int i = 0; i < length; ++i) {
		encrypted_sentence[i] = t[i] - shift;

	}
	encrypted_sentence[length] = '\0';  // Dodaj znak koñca ci¹gu
	return encrypted_sentence;
}