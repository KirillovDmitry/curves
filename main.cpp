#include <iostream>
#include <functional>
#include <vector>
#include "LineCurve.h" 
#include "SinCurve.h" 
#include "CosCurve.h" 
#include "QuadraticCurve.h" 
#include "EllipsCurve.h" 
#include "CircuitCurve.h" 

int main()
{
    std::vector<std::shared_ptr<Curve>> Curves;
    Curves.reserve(10);

    // создание кривых разных типов и занесение их в вектор
    Curves.push_back(std::make_shared<LineCurve>(LineCurve(0, 3, 1, 1)) );
    Curves.push_back(std::make_shared<QuadraticCurve>(QuadraticCurve(0, 3, 4, 0, 0)));
    Curves.push_back(std::make_shared<SinCurve>(SinCurve(0, 3, 1, 1, 0)));
    Curves.push_back(std::make_shared<CosCurve>(CosCurve(0, 3, 1, 1, 0)));
    Curves.push_back(std::make_shared<EllipsCurve>(EllipsCurve(0, 3, 1, 2, 1, 0)));
    Curves.push_back(std::make_shared<CircuitCurve>(CircuitCurve(0, 3, 1, 1, 0)));

    double t = 0.5;

    // вывод в консоль значения функции в точке t
    for (unsigned int i = 0; i < Curves.size(); ++i)
        std::cout << "The value of the curve '" << Curves[i]->get_name() <<
        "' at point t = " << t << " is equal to " << "(" << Curves[i]->get_point(t).x1 <<
        ", " << Curves[i]->get_point(t).x2 << ")" << std::endl;

    std::cout << "---------------" << std::endl;

    // вывод в консоль значения первой производной функции в точке t
    for (unsigned int i = 0; i < Curves.size(); ++i)
        std::cout << "The value of the first derivative '" << Curves[i]->get_name() <<
        "' at point t = " << t << " is equal to " <<  Curves[i]->get_first_derivative(t) << " "<< std::endl;

    std::cout << "---------------" << std::endl;

    // вывод в консоль значения второй производной функции в точке t
    for (unsigned int i = 0; i < Curves.size(); ++i)
        std::cout << "The value of the second derivative '" << Curves[i]->get_name() <<
        "' at point t = " << t << " is equal to " << Curves[i]->get_second_derivative(t) << std::endl;
    
    std::cout << "---------------" << std::endl;

    // вывод в консоль значения длины кривой
    for (unsigned int i = 0; i < Curves.size(); ++i)
        std::cout << "The value of curve's length '" << Curves[i]->get_name() <<
        "' is equal to " << Curves[i]->get_length() << std::endl;

    std::cout << "---------------" << std::endl;

    Point P(2, 2);
    // вывод в консоль проекции точки P на кривую
    for (unsigned int i = 0; i < Curves.size(); ++i)
        std::cout << "Projection of a point " << "(" << P.x1 << ", " << P.x2 << ")" <<
        " onto a curve '" << Curves[i]->get_name() <<
        "' is equal to (" <<
        Curves[i]->get_point(Curves[i]->get_projection(P)).x1 << ", " <<
        Curves[i]->get_point(Curves[i]->get_projection(P)).x2 << ") " << std::endl;

    std::cout << "---------------" << std::endl;

    // Проверка функции выдачи локальной системы координат.
    // Для окружности с центром в (0,0) и радиусом 1 в точках (0 + n*PI/4) выводится локальная система координат.

    CircuitCurve C = CircuitCurve(0, 3, 1, 1, 0);

    std::pair<Vector, Vector> N = C.get_local(0);
    for (double alpha = 0; alpha <= 2 * PI; alpha += PI / 4) {
        std::cout << "alpha = " << alpha << std::endl;
        N = C.get_local(alpha);
        std::cout << "Normal = (" << N.first.begin.x1 << "; " << N.first.begin.x2 << "), " <<
            " (" << N.first.end.x1 << ";" << N.first.end.x2 << ") " << std::endl;
        std::cout << "Tangent = (" << N.second.begin.x1 << "; " << N.second.begin.x2 << "), " <<
            " (" << N.second.end.x1 << ";" << N.second.end.x2 << ") " << std::endl;
        std::cout << "---------------" << std::endl;
    }

}
