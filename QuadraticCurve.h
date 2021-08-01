#ifndef QuadraticCurve_H
#define QuadraticCurve_H

#include "Curve.h"

// �����, ����������� ��������
class QuadraticCurve : public Curve
{
private:
	double a;
	double b;
	double c;

public:
	QuadraticCurve(double t_begin_, double t_end_, double a_ = 1, double b_ = 0, double c_ = 0) : Curve(t_begin_, t_end_),
		a(a_), b(b_), c(c_) {};
	
	// �����, ���������� ������� ����� get_point()
	Point get_point(double t);

	// �������������� ������, ������������ ������������ ���������� �������� �����������.
	double get_first_derivative_analytical(double t);
	double get_second_derivative_analytical(double t);
	std::string get_name();
};

#endif

