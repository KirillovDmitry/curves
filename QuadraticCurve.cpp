#include "QuadraticCurve.h"

// вычисление значения функции, соответствующего параметру t
Point QuadraticCurve::get_point(double t) {
	return local_point(point(t));
}

// вычисление значения функции, соответствующего параметру t в декартовой системе координат
Point QuadraticCurve::point(double t) {
	return Point((t, a*t*t + b*t + c));
}

// метод, возвращающий наименование кривой.
std::string QuadraticCurve::get_name() {
	return "quadratic";
}
