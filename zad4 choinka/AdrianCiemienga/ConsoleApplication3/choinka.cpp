#include "choinka.h"

using namespace std;

Choinka::Choinka(int dlugosc) : dlugosc(dlugosc) {}

void Choinka::rysuj() {
	for (int i = 1; i <= dlugosc; i++) {
		for (int j = 1; j <= dlugosc * 3 - i - 1; j++) {
			cout << " ";
		}
		for (int k = 1; k <= i * 2 - 1; k++) {
			cout << "*";
		}
		cout << endl;
	}
	for (int i = dlugosc + 1 - 2; i < 2 * dlugosc + 1; i++) {
		for (int j = 1; j <= dlugosc * 3 - i - 1; j++) {
			cout << " ";
		}
		for (int k = 1; k <= i * 2 - 1; k++) {
			cout << "*";
		}
		cout << endl;
	}
	for (int i = dlugosc * 2 + 1 - 4; i < dlugosc * 3 - 1; i++) {
		for (int j = 1; j <= dlugosc * 3 - i - 1; j++) {
			cout << " ";
		}
		for (int k = 1; k <= i * 2 - 1; k++) {
			cout << "*";
		}
		cout << endl;
	}
	for (int i = 1; i <= dlugosc; i++) {
		for (int j = 1; j < (6 * dlugosc - 1) / 2 - 1; j++) {
			cout << " ";
		}
		cout << "*" << endl;
	}
}