#ifndef CosCurve_H
#define CosCurve_H

#include "Curve.h"

// класс, реализующий функцию cos()
class CosCurve : public Curve
{
private:
	double ampl; // амплитуда 
	double w;	 // круговая частота
	double phi;  // начальная фаза

public:
	CosCurve(double t_begin_, double t_end_, double ampl_ = 1, double w_ = 1, double phi_ = 1) : Curve(t_begin_, t_end_),
		ampl(ampl_), w(w_), phi(phi_) {};

	// метод, замещающий базовый метод get_point()
	Point get_point(double t);

	// дополнительные методы, использующие аналитически вычисленные значения производных.
	double get_first_derivative_analytical(double t);
	double get_second_derivative_analytical(double t);
	std::string get_name();
};

#endif
