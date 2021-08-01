#ifndef Point_H
#define Point_H

// ��������� �����
struct Point
{
	double x1, x2; // ������ � ������ ���������� �����
	// �����������
	Point(double x1_, double x2_) : x1(x1_), x2(x2_) {};

	// �����������, ������������� double � Point
	Point(double x1_) : x1(x1_), x2(x1_) {};

	// ������������� �������, ������������� �������������� �������� ��� ���� Point
	friend Point operator-(Point a, Point b);
	friend Point operator+(Point a, Point b);
	friend Point operator/(Point a, Point b);
	friend Point operator*(Point a, Point b);
};

#endif
