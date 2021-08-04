#include "CosCurve.h"

// вычисление значения функции, соответствующего параметру t
Point CosCurve::get_point(double t) {
	return local_point(point(t));
}

// вычисление значения функции, соответствующего параметру t в декартовой системе координат
Point CosCurve::point(double t) {
	return Point(t, ampl*cos(w*t + phi));
}


// метод, возвращающий наименование кривой.
std::string CosCurve::get_name() {
	return "cos";
}



