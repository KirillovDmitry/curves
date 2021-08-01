#include "SinCurve.h"

// вычисление значения функции, соответствующего параметру t
Point SinCurve::get_point(double t) {
	return Point(t, ampl*sin(w*t + phi));
}

// вычисление значения первой производной аналитически
double SinCurve::get_first_derivative_analytical(double t) {
	return -ampl*w*cos(w*t + phi);
}

// вычисление значения второй производной аналитически
double SinCurve::get_second_derivative_analytical(double t) {
	return ampl*w*w*sin(w*t + phi);
}

// метод, возвращающий наименование кривой.
std::string SinCurve::get_name() {
	return "sin";
}

