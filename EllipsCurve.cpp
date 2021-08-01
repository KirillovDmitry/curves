#include "EllipsCurve.h"

// ���������� �������� �������, ���������������� ��������� t
Point EllipsCurve::get_point(double t) {
	return  Point(a*cos(w*t + phi), b*sin(w*t + phi));
}

// ���������� �������� ������ ����������� ������������
double EllipsCurve::get_first_derivative_analytical(double t) {
	return -b*w*cos(w*t + phi) / a*w*sin(w*t + phi);
}

// ���������� �������� ������ ����������� ������������
double EllipsCurve::get_second_derivative_analytical(double t) {
    
    // ������ ����������� ������ ������� � ����� t
    std::pair<double, double> P1(a*w*sin(w*t + phi), -b*w*cos(w*t + phi));

    // ������ ����������� ������ ������� � ����� t
    std::pair<double, double> P2(-a*w*w*cos(w*t + phi), -b*w*w*sin(w*t + phi));

    double A = P1.first * P2.second;
    double B = P1.second * P2.first;

    // �������� ������� �� ����
    if (P1.first == 0)
        P1.first = std::numeric_limits<double>::min();

    return (A - B) / pow(P1.first, 3); 
}

// �����, ������������ ������������ ������.
std::string EllipsCurve::get_name() {
    return "ellips";
}
