#include "SinCurve.h"

// ���������� �������� �������, ���������������� ��������� t
Point SinCurve::get_point(double t) {
	return Point(t, ampl*sin(w*t + phi));
}

// ���������� �������� ������ ����������� ������������
double SinCurve::get_first_derivative_analytical(double t) {
	return -ampl*w*cos(w*t + phi);
}

// ���������� �������� ������ ����������� ������������
double SinCurve::get_second_derivative_analytical(double t) {
	return ampl*w*w*sin(w*t + phi);
}

// �����, ������������ ������������ ������.
std::string SinCurve::get_name() {
	return "sin";
}

