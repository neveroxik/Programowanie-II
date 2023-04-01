#define _USE_MATH_DEFINES

#include <cmath>
#include "Walec.h"

template<typename T>
Walec<T>::Walec(T r, T h) : r(r), h(h) {};

template<typename T>
T Walec<T>::pole() {
	return 2 * M_PI * r * r + 2 * M_PI * r * h;
}

template class Walec<int>;
template class Walec<double>;
template class Walec<float>;