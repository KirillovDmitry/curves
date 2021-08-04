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
	LineCurve(type_of_coordinate_system CS, double t_begin_, double t_end_, double k_ = 1, double b_ = 0) : Curve(CS, t_begin_, t_end_),
		k(k_), b(b_) {};

	// метод, замещающий базовый метод get_point()
	Point get_point(double t);

	// метод, замещающий базовый метод point()
	Point point(double t);

	std::string get_name();
};

#endif

