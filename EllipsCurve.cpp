#include "EllipsCurve.h"

// вычисление значения функции, соответствующего параметру t
Point EllipsCurve::get_point(double t) {
	return  Point(a*cos(w*t + phi), b*sin(w*t + phi));
}

// вычисление значения первой производной аналитически
double EllipsCurve::get_first_derivative_analytical(double t) {
	return -b*w*cos(w*t + phi) / a*w*sin(w*t + phi);
}

// вычисление значения второй производной аналитически
double EllipsCurve::get_second_derivative_analytical(double t) {
    
    // первая производная каждой функции в точке t
    std::pair<double, double> P1(a*w*sin(w*t + phi), -b*w*cos(w*t + phi));

    // вторая производная каждой функции в точке t
    std::pair<double, double> P2(-a*w*w*cos(w*t + phi), -b*w*w*sin(w*t + phi));

    double A = P1.first * P2.second;
    double B = P1.second * P2.first;

    // возможно деление на ноль
    if (P1.first == 0)
        P1.first = std::numeric_limits<double>::min();

    return (A - B) / pow(P1.first, 3); 
}

// метод, возвращающий наименование кривой.
std::string EllipsCurve::get_name() {
    return "ellips";
}
