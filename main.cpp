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

     /*//Curve C(0, 1);
    LineCurve C1(0, 1, 1, 1);
    QuadraticCurve C2(0, 1, 4, 0, 0);
    SinCurve C3(0, 3, 1, 1, 0);
    CosCurve C4(0, 3, 1, 1, 0);
    EllipsCurve  C5(0, 3, 1, 1, 1, 0);
    CircuitCurve C6(0, 3, 1, 1, 0);
   std::cout << "X1 = " << C.get_point(0.5).x1  << "; X2 = " << C.get_point(0.5).x2  << std::endl;
    std::cout << "X1 = " << C1.get_point(0.5).x1 << "; X2 = " << C1.get_point(0.5).x2 << std::endl;
    std::cout << "X1 = " << C2.get_point(0.5).x1 << "; X2 = " << C2.get_point(0.5).x2 << std::endl;
    std::cout << "X1 = " << C3.get_point(0.5).x1 << "; X2 = " << C3.get_point(0.5).x2 << std::endl;
    std::cout << "X1 = " << C4.get_point(0.5).x1 << "; X2 = " << C4.get_point(0.5).x2 << std::endl;
    std::cout << "X1 = " << C5.get_point(0.5).x1 << "; X2 = " << C5.get_point(0.5).x2 << std::endl;
    std::cout << "X1 = " << C6.get_point(0.5).x1 << "; X2 = " << C6.get_point(0.5).x2 << std::endl;
    std::cout << "---------------" << std::endl;
    std::cout << "X1 = " << C.get_first_derivative(0.5)  << std::endl;
    std::cout << "X1 = " << C1.get_first_derivative(0.5) << std::endl;
    std::cout << "X1 = " << C2.get_first_derivative(0.5) << std::endl;
    std::cout << "X1 = " << C3.get_first_derivative(0.5) << std::endl;
    std::cout << "X1 = " << C4.get_first_derivative(0.5) << std::endl;
    std::cout << "X1 = " << C5.get_first_derivative(0.5) << std::endl;
    std::cout << "X1 = " << C6.get_first_derivative(0.5) << std::endl;
    std::cout << "---------------" << std::endl;
   
    //std::cout << "X1 = " << C.get_second_derivative(0.5) << std::endl;
    std::cout << "X1 = " << C1.get_second_derivative(0.5) << std::endl;
    std::cout << "X1 = " << C2.get_second_derivative(0.5) << std::endl;
    std::cout << "X1 = " << C3.get_second_derivative(0.5) << std::endl;
    std::cout << "X1 = " << C4.get_second_derivative(0.5) << std::endl;
    std::cout << "X1 = " << C5.get_second_derivative(0.5) << std::endl;
    std::cout << "X1 = " << C6.get_second_derivative(0.5) << std::endl;
    std::cout << "X1 = " << Curves[0]->get_second_derivative(0.5) << std::endl;
    std::cout << "---------------" << std::endl;
 */
  //  for (unsigned int i = 0; i < Curves.size(); ++i)
  //      delete Curves[i];

   /*std::cout << "X1 = " << C.get_length() << std::endl;
    std::cout << "X1 = " << C1.get_length() << std::endl;
    std::cout << "X1 = " << C2.get_length() << std::endl;
    std::cout << "X1 = " << C3.get_length() << std::endl;
    std::cout << "X1 = " << C4.get_length() << std::endl;
    std::cout << "X1 = " << C5.get_length() << std::endl;
    std::cout << "X1 = " << C6.get_length() << std::endl;
    std::cout << "---------------" << std::endl;
    */
    //std::cout << "X1 = " << C.get_projection(Point(0,  2)) << std::endl;
    //std::cout << "X1 = " << C1.get_projection(Point(0, 2)) << std::endl;
    //std::cout << "X1 = " << C2.get_projection(Point(0, 2)) << std::endl;
    //std::cout << "X1 = " << C3.get_projection(Point(5, 5)) << std::endl;
    //std::cout << "X1 = " << C4.get_projection(Point(5, 5)) << std::endl;
    //std::cout << "X1 = " << C5.get_projection(Point(5, 5)) << std::endl;
    //std::cout << "X1 = " << C6.get_projection(Point(0, 5)) << std::endl;
    //std::cout << "X1 = " << C5.get_projection_(Point(0, 5)) << std::endl;
    /*
    // Function f1, f2;
    Line_function    line1(2, 0) , line2(1, 1);
    Square_function  parabola(1, 0, 0);
    Circuit_function ring(1, 1, 0);
    Sin_function sin(1, 1, 0);
 
    Curve C(0, 1, parabola);
    double t = 1;
    Point p = C.get_point(t);
    std::cout << "X1 = " << p.x1 << "; X2 = " << p.x2 << std::endl;

    double D1 = C.get_first_derivative(t);
    std::cout << "D1 = " << D1 << std::endl;
    
    double D2 = C.get_second_derivative(t);
    std::cout << "D2 = " << D2 << std::endl;

    double L = C.get_length(1e-6);
    std::cout << "L = " << L << std::endl;
    */
}
