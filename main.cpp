#include <iostream>
#include <functional>
#include <cassert>
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
    type_of_coordinate_system CS_1(cartesian);
    Curves.push_back(std::make_shared<LineCurve>(LineCurve(CS_1, 0, 3, 1, 0)) );
    Curves.push_back(std::make_shared<QuadraticCurve>(QuadraticCurve(CS_1, 0, 3, 4, 0, 0)));
    Curves.push_back(std::make_shared<SinCurve>(SinCurve(CS_1, 0, 3, 1, 1, 0)));
    Curves.push_back(std::make_shared<CosCurve>(CosCurve(CS_1, 0, 3, 1, 1, 0)));
    Curves.push_back(std::make_shared<EllipsCurve>(EllipsCurve(CS_1, 0, 3, 1, 2, 1, 0)));
    Curves.push_back(std::make_shared<CircuitCurve>(CircuitCurve(CS_1, 0, 3, 1, 1, 0)));

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

    std::vector<double> Lengths_decart;
    Lengths_decart.reserve(10);
    Curves.reserve(10);
    // вывод в консоль значения длины кривой
    for (unsigned int i = 0; i < Curves.size(); ++i) {
        Lengths_decart.push_back(Curves[i]->get_length());
        std::cout << "The value of curve's length '" << Curves[i]->get_name() <<
            "' is equal to " << Lengths_decart[i] << std::endl;
    }

    std::cout << "---------------" << std::endl;

    Point P(3, 1);
    // вывод в консоль проекции точки P на кривую
    for (unsigned int i = 0; i < Curves.size(); ++i)
        std::cout << "Projection of a point " << "(" << P.x1 << ", " << P.x2 << ")" <<
        " onto a curve '" << Curves[i]->get_name() <<
        "' is equal to (" <<
        Curves[i]->get_point(Curves[i]->get_projection(P)).x1 << ", " <<
        Curves[i]->get_point(Curves[i]->get_projection(P)).x2 << ") " << std::endl;

    std::cout << "---------------" << std::endl;

    // Тестирование сферической системы координат.
    // Создание кривых в сферической системе координат с параметрами, соответсвующими аналогичным кривым
    // в декартовой системе координат. Так как конкретная кривая не зависит от типа системы координат,
    // то ее длина должна быть одинаковой в любых системах координат. Справедливоть данного утверждения
    // и проверяется приведенным ниже тестом.
       
    std::cout << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << std::endl;
    std::cout << "Spherical system testing: " << std::endl;
    type_of_coordinate_system CS_2(spherical);
    std::vector<std::shared_ptr<Curve>> Curves_spherical;
    
    Curves_spherical.reserve(10);

    Curves_spherical.push_back(std::make_shared<LineCurve>(LineCurve(CS_2, 0, 3, 1, 0)));
    Curves_spherical.push_back(std::make_shared<QuadraticCurve>(QuadraticCurve(CS_2, 0, 3, 4, 0, 0)));
    Curves_spherical.push_back(std::make_shared<SinCurve>(SinCurve(CS_2, 0, 3, 1, 1, 0)));
    Curves_spherical.push_back(std::make_shared<CosCurve>(CosCurve(CS_2, 0, 3, 1, 1, 0)));
    Curves_spherical.push_back(std::make_shared<EllipsCurve>(EllipsCurve(CS_2, 0, 3, 1, 2, 1, 0)));
    Curves_spherical.push_back(std::make_shared<CircuitCurve>(CircuitCurve(CS_2, 0, 3, 1, 1, 0)));
    
    std::vector<double> Lengths_spherical;
    
    // вывод в консоль значения длины кривой в сферической системе координат
    for (unsigned int i = 0; i < Curves_spherical.size(); ++i) {
        Lengths_spherical.push_back( Curves_spherical[i]->get_length());
        std::cout << "The value of curve's length '" << Curves_spherical[i]->get_name() <<
            "' is equal to " << Lengths_spherical[i] << std::endl;

        // проверка на равенство длин кривых в разных системах координат
        assert(abs(Lengths_spherical[i] - Lengths_decart[i]) < 1e-4);
    }
   
    std::cout << "---------------" << std::endl;
    
}
