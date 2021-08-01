#include "QuadraticCurve.h"

// ���������� �������� �������, ���������������� ��������� t
Point QuadraticCurve::get_point(double t) {
	return Point(t, a*t*t + b*t + c);
}

// ���������� �������� ������ ����������� ������������
double QuadraticCurve::get_first_derivative_analytical(double t) {
	return 2*a*t + b;
}

// ���������� �������� ������ ����������� ������������
double QuadraticCurve::get_second_derivative_analytical(double t) {
	return 2*a;
}

// �����, ������������ ������������ ������.
std::string QuadraticCurve::get_name() {
	return "quadratic";
}
