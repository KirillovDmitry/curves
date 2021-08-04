#include "LineCurve.h"

// вычисление значения функции, соответствующего параметру t
Point LineCurve::get_point(double t) {
	return local_point(point(t));
}

// вычисление значения функции, соответствующего параметру t в декартовой системе координат
Point LineCurve::point(double t) {
	return Point(t, k*t + b);
}

// метод, возвращающий наименование кривой.
std::string LineCurve::get_name() {
	return "segment";
}