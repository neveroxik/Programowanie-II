#pragma once
#include <iostream>
#include <string>
using namespace std;

class Wektor {
private:
    int x, y, z;

public:
    Wektor(int x = 0, int y = 0, int z = 0);

    // jednoargumentowe 
    Wektor operator ++ ();
    Wektor operator -- ();

    // dwuargumentowe 
    Wektor operator - (const Wektor& obj) const;
    Wektor operator + (const Wektor& obj) const;

    string GetWektor();
};
