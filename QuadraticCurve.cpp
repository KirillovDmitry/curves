#include "QuadraticCurve.h"

// вычисление значения функции, соответствующего параметру t
Point QuadraticCurve::get_point(double t) {
	return Point(t, a*t*t + b*t + c);
}

// вычисление значения первой производной аналитически
double QuadraticCurve::get_first_derivative_analytical(double t) {
	return 2*a*t + b;
}

// вычисление значения второй производной аналитически
double QuadraticCurve::get_second_derivative_analytical(double t) {
	return 2*a;
}

// метод, возвращающий наименование кривой.
std::string QuadraticCurve::get_name() {
	return "quadratic";
}
