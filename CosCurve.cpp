#include "CosCurve.h"

// вычисление значения функции, соответствующего параметру t
Point CosCurve::get_point(double t) {
	return Point(t, ampl*cos(w*t + phi));
}

// вычисление значения первой производной аналитически
double CosCurve::get_first_derivative_analytical(double t) {
	return ampl*w*sin(w*t + phi);
}

// вычисление значения второй производной аналитически
double CosCurve::get_second_derivative_analytical(double t) {
	return -ampl*w*w*cos(w*t + phi);
}

// метод, возвращающий наименование кривой.
std::string CosCurve::get_name() {
	return "cos";
}



