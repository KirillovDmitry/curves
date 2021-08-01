#ifndef LineCurve_H
#define LineCurve_H

#include "Curve.h"

// класс, реализующий линейную функцию
class LineCurve : public Curve
{
private:
	double k;
	double b;

public:
	LineCurve(double t_begin_, double t_end_, double k_ = 1, double b_ = 0) : Curve(t_begin_, t_end_),
		k(k_), b(b_) {};

	// метод, замещающий базовый метод get_point()
	Point get_point(double t);

	// дополнительные методы, использующие аналитически вычисленые значения.
	double get_first_derivative_analytical(double t);
	double get_second_derivative_analytical(double t);
	double get_length_analytical();
	std::string get_name();
};

#endif

