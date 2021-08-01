#ifndef EllipsCurve_H
#define EllipsCurve_H

#include "Curve.h"

// класс, реализующий эллипс
class EllipsCurve : public  Curve {

private:
	double a;   // полуось 
	double b;   // полуось
	double w;   // круговая частота
	double phi; // начальная фаза

public:
	EllipsCurve(double t_begin_, double t_end_, double a_, double b_,
		double w_, double phi_) : Curve(t_begin_, t_end_), a(a_), b(b_), w(w_), phi(phi_) {};

	// метод, замещающий базовый метод get_point()
	virtual Point get_point(double t);

	// дополнительные методы, использующие аналитически вычисленые значения производных.
	virtual double get_first_derivative_analytical(double t);
	virtual double get_second_derivative_analytical(double t);
	virtual std::string get_name();
};

#endif

