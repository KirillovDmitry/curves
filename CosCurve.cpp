#include "CosCurve.h"

// ���������� �������� �������, ���������������� ��������� t
Point CosCurve::get_point(double t) {
	return Point(t, ampl*cos(w*t + phi));
}

// ���������� �������� ������ ����������� ������������
double CosCurve::get_first_derivative_analytical(double t) {
	return ampl*w*sin(w*t + phi);
}

// ���������� �������� ������ ����������� ������������
double CosCurve::get_second_derivative_analytical(double t) {
	return -ampl*w*w*cos(w*t + phi);
}

// �����, ������������ ������������ ������.
std::string CosCurve::get_name() {
	return "cos";
}



