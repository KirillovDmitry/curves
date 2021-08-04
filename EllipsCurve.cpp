#include "EllipsCurve.h"

// вычисление значения функции, соответствующего параметру t
Point EllipsCurve::get_point(double t) {
	return local_point(point(t));
}

// вычисление значения функции, соответствующего параметру t в декартовой системе координат
Point EllipsCurve::point(double t) {
	return Point(a*cos(w*t + phi), b*sin(w*t + phi));
}

// метод, возвращающий наименование кривой.
std::string EllipsCurve::get_name() {
    return "ellips";
}
