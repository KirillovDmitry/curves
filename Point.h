#ifndef Point_H
#define Point_H

// двумерная точка
struct Point
{
	double x1, x2; // первая и вторая координаты точки
	// конструктор
	Point(double x1_, double x2_) : x1(x1_), x2(x2_) {};

	// конструктор, преобразующий double к Point
	Point(double x1_) : x1(x1_), x2(x1_) {};

	// дружественные функции, перегружающие арифметические операции для типа Point
	friend Point operator-(Point a, Point b);
	friend Point operator+(Point a, Point b);
	friend Point operator/(Point a, Point b);
	friend Point operator*(Point a, Point b);
};

#endif
