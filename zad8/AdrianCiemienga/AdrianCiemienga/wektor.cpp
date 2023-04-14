#include "wektor.h"

Wektor::Wektor(int x, int y, int z) : x(x), y(y), z(z) {}

Wektor Wektor::operator ++ ()
{
    return Wektor(x++, y++, z++);
}

Wektor Wektor::operator -- (){
    return Wektor(x--, y--, z--);
}

Wektor Wektor::operator - (const Wektor& obj) const{
    return Wektor(x - obj.x, y - obj.y, z - obj.z);
}

Wektor Wektor::operator + (const Wektor& obj) const{
    return Wektor(x + obj.x, y + obj.y, z + obj.z);
}

string Wektor::GetWektor(){
    return "x: " + to_string(x) + ", y:" + to_string(y) + ", z:" + to_string(z);
}
