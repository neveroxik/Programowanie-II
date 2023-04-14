#include "klasa.h"

int main() {
    double a, b;
    cout << "Podaj dwie liczby: ";
    cin >> a >> b;
    Klasa Klasa(a, b);

    cout << "Dzielenie:" << endl;

    try 
    {
        cout << "Wynik dzielenia: " << Klasa.dzielenie() << endl;
    }
    catch (const char* alert) 
    {
        cerr << "Blad: " << alert << endl;
    }

    cout << endl << "modulo:" << endl;

    try 
    {
        cout << "Wynik operacji modulo: " << Klasa.modulo() << endl;
    }
    catch (const char* alert) 
    {
        cerr << "Blad: " << alert << endl;
    }

    return 0;
}