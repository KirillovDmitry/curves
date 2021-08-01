#include "Point.h"

// �������������� �������� ��� ���� Point

Point operator+(Point a, Point b) {
	return Point(a.x1 + b.x1, a.x2 + b.x2);
};

Point operator-(Point a, Point b) {
	return Point(a.x1 - b.x1, a.x2 - b.x2);
};

Point operator/(Point a, Point b) {
	return Point(a.x1 / b.x1, a.x2 / b.x2);
};

Point operator*(Point a, Point b) {
	return Point(a.x1 * b.x1, a.x2 * b.x2);
};

