#include<iostream>
using namespace std;

int main() {
    int n;
    double P = 0;
    cout << "Give n" << endl;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        P += 1 / pow(i, 2);
    }
    P = sqrt(6 * P);
    cout << P << endl;
}
