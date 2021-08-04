#ifndef QuadraticCurve_H
#define QuadraticCurve_H

#include "Curve.h"

// класс, реализующий параболу
class QuadraticCurve : public Curve
{
private:
	double a;
	double b;
	double c;

public:
	QuadraticCurve(type_of_coordinate_system CS, double t_begin_, double t_end_, double a_ = 1, double b_ = 0, double c_ = 0) : Curve(CS, t_begin_, t_end_),
		a(a_), b(b_), c(c_) {};
	
	// метод, замещающий базовый метод point()
	Point point(double t);

	// метод, замещающий базовый метод get_point()
	Point get_point(double t);

	std::string get_name();
};

#endif

