#include "Klasy.h"

#define _USE_MATH_DEFINES
#include <math.h>

Obiekt::~Obiekt() {
	cout << "wirtualny destruktor" << endl;
}
void Obiekt::pole() {}

Kolo::Kolo() {}
Kolo::Kolo(double r) : r(r) {}
void Kolo::pole() {
	cout << "pole kola wynosi: " << M_PI * r * r << endl;
}
Kolo::~Kolo() {
	cout << "destruktor kolo" << endl;
}


Walec::Walec(double r, double h) : r(r), h(h) {}
void Walec::pole() {
	cout << "pole walca wynosi: " << 2 * M_PI * r * r + 2 * M_PI * r * h << endl;
}
Walec::~Walec() {
	cout << "destruktor walec" << endl;
}


Kwadrat::Kwadrat() {}
Kwadrat::Kwadrat(double a) : a(a) {}
void Kwadrat::pole() {
	cout << "pole kwadratu wynosi: " << a * a << endl;
}
Kwadrat::~Kwadrat() {
	cout << "destruktor kwadrat" << endl;
}


Szescian::Szescian(double a) : a(a) {}
void Szescian::pole() {
	cout << "pole szescianu wynosi: " << a * a * 6 << endl;
}
Szescian::~Szescian() {
	cout << "destruktor szescian" << endl;
}


void oblicz(Obiekt* wsk) {
	wsk->pole();
}