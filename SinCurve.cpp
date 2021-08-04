#include "SinCurve.h"

// вычисление значения функции, соответствующего параметру t
Point SinCurve::get_point(double t) {
	return local_point(point(t));
}

// вычисление значения функции, соответствующего параметру t в декартовой системе координат
Point SinCurve::point(double t) {
	return Point(t, ampl*sin(w*t + phi));
}
// метод, возвращающий наименование кривой.
std::string SinCurve::get_name() {
	return "sin";
}

