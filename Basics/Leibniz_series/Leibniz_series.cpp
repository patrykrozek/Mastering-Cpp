#include <iostream>
using namespace std;

int main() {
    int n;
    double P = 0, licznik = 1;
    cout << "Podaj n" << endl;
    cin >> n;
    for (int i = 1; i <= n; i += 2) {
        P += licznik / i;
        licznik *= -1;
    }
    P = 4 * P;
    cout << P << endl;
}


//Kotek kotek kotek
