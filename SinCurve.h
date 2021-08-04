#ifndef SinCurve_H
#define SinCurve_H

#include "Curve.h"

// класс, реализующий функцию sin()
class SinCurve : public Curve
{
private:
	double ampl; // амплитуда 
	double w;	 // круговая частота
	double phi;  // начальная фаза

public:
	SinCurve(type_of_coordinate_system CS, double t_begin_, double t_end_, double ampl_ = 1, double w_ = 1, double phi_ = 1) : Curve(CS, t_begin_, t_end_),
		ampl(ampl_), w(w_), phi(phi_) {};

	// метод, замещающий базовый метод get_point()
	Point get_point(double t);

	// метод, замещающий базовый метод point()
	Point point(double t);

	std::string get_name();
};

#endif

