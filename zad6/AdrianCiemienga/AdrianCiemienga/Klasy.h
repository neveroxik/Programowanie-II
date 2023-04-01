#pragma once
#include <iostream>

using namespace std;

class Obiekt {
public:
	virtual void pole() = 0;
	virtual ~Obiekt();
};

class Kolo : public Obiekt {
	double r;
public:
	Kolo();
	Kolo(double r);
	void pole();
	~Kolo();
};

class Walec : public Kolo {
	double r;
	double h;
public:
	Walec(double r, double h);
	void pole();
	~Walec();
};

class Kwadrat : public Obiekt {
	double a;
public:
	Kwadrat();
	Kwadrat(double a);
	void pole();
	~Kwadrat();
};

class Szescian : public Kwadrat {
	double a;
public:
	Szescian(double a);
	void pole();
	~Szescian();
};

void oblicz(Obiekt* wsk);