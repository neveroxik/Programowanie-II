#include "wektor.h"

int main() {
    Wektor wek1(4, 1, 4);
    Wektor wek2(1, 3, 5);
    cout << "wek1 = " << wek1.GetWektor() << endl;
    cout << "wek2 = " << wek2.GetWektor() << endl << endl;

    Wektor wek3 = ++wek1;
    Wektor wek4 = --wek2;
    Wektor wek5 = wek4 - wek3;
    Wektor wek6 = wek4 + wek3;
    cout << "wek1 = " << wek1.GetWektor() << endl;
    cout << "wek2 = " << wek2.GetWektor() << endl;
    cout << "wek3(++wek1) = " << wek3.GetWektor() << endl;
    cout << "wek4(--wek2) = " << wek4.GetWektor() << endl;
    cout << "wek5(wek4-wek3) = " << wek5.GetWektor() << endl;
    cout << "wek6(wek4+wek3) = " << wek6.GetWektor() << endl;

    return 0;
}
