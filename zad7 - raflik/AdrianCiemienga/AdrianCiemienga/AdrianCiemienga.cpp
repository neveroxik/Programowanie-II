#include <iostream>
#include "Walec.h"

using namespace std;

template<typename T> T max(T a, T b, T c) {
    if (a > b && a > c) {
        return a;
    }
    else if (b > a && b > c) {
        return b;
    }
    else {
        return c;
    }
}

int main() {
    double a = -10.5, b = 6.24, c = 0.1;
    cout << "Najwieksza wartosc z podanych argumentow: " << max(a, b, c) << endl;

    cout << "*****************************" << endl;

    Walec<double> walec(4, 10);
    cout << "Pole powierzchni walca wynosi: " << walec.pole() << endl;

    return 0;
}