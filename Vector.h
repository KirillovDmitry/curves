#ifndef Vector_H
#define Vector_H

#include "Point.h"

// �����, ����������� ������ ����� ��������� � �������� �����
class Vector
{
public:
	Point begin;
	Point end;

	Vector(Point begin_ = Point(0, 0), Point end_ = Point(1, 1)) : begin(begin_), end(end_) {}

};

#endif

