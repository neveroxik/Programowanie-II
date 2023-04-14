#include "klasa.h"

Klasa::Klasa(double a, double b) : a(a), b(b) {}

double Klasa::dzielenie()
{
    if (b == 0) {
        throw "nie mozna dzielic przez 0";
    }
    return a/b;
}

int Klasa::modulo()
{
    if ((int)b == 0)
        throw "nie mozna dzielic przez 0";
    else if ((int)a == (int)b)
        throw "blad, liczby sa takie same";
    else if ((int)a % (int)b == 0 || (int)b % (int)a == 0)
        throw "blad, jedna z liczb jest wielokrotnoscia drugiej liczby";
    return (int)a % (int)b;
}
