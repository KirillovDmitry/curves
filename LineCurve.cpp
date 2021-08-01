#include "LineCurve.h"

// ���������� �������� �������, ���������������� ��������� t
Point LineCurve::get_point(double t) {
	return Point(t, k * t + b);
}

// ���������� �������� ������ ����������� ������������
double LineCurve::get_first_derivative_analytical(double t) {
	return k;
}

// ���������� �������� ������ ����������� ������������
double LineCurve::get_second_derivative_analytical(double t) {
	return 0;
}

// ���������� ����� ������ ������������
double LineCurve::get_length_analytical() {
	Point X = get_point(t_begin);
	Point Y = get_point(t_end); 
	return sqrt( pow(X.x1-Y.x1, 2) + pow(X.x2 - Y.x2, 2));
}

// �����, ������������ ������������ ������.
std::string LineCurve::get_name() {
	return "segment";
}