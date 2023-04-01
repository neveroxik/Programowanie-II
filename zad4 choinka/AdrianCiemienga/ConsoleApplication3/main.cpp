#include "choinka.h"

using namespace std;

int main()
{
    int dlugosc;

    cout << "Wprowadz liczbe linii 1 bloku: " << endl;
    cin >> dlugosc;

    Choinka choinka(dlugosc);

    cout << "Choinka" << endl;

    choinka.rysuj();
}