#include "Curve.h"

// вычисление точки кривой, соответствующей заданному параметру t 
Point Curve::get_point(double t) {
	// по умолчанию в качестве кривой используется прямая y = x
    return Point(t,t);
}

// выдача информации об области определения параметра кривой t.
// возвращаемое значение - пара начального и конечного значения параметра t.
std::pair<double, double> Curve::get_param() {
	return std::make_pair(t_begin, t_end);
}

// вычисление первой производной кривой в точке t с приращением конечной разности функции на шаг h
double Curve::get_first_derivative(double t, double h) {
    // вычисление производных одномерных функций y(t) и x(t) в точке t
    std::pair<double, double> P = first_derivative(t, h);
    
    // если производная  x'(t) в точке t равняется 0, при последующем делении на ноль сгенерируется inf.
    // произведем замену нуля на очень малое число.
    if (P.first == 0)
        P.first = std::numeric_limits<double>::min();
    
    // производная в декартовой системе координат равняется y'/x' (дифференцирование производится по параметру t)
    return P.second / P.first; // возможно деление на ноль. необходимо бросить исключение, либо сформировать код ошибки
}

// вычисление второй производной кривой в точке t с приращением конечной разности функции на шаг h
double Curve::get_second_derivative(double t, double h) {

    // первая производная каждой функии y(t) и x(t) в точке t
    std::pair<double, double> P1 = first_derivative(t, h);
    
    // вторая производная каждой функии y(t) и x(t) в точке t
    std::pair<double, double> P2 = second_derivative(t, h);

    // вычисление второй производной параметрически заданной кривой по формуле
    // (x'(t)*y''(t) - y'(t)*x''(t)) / x'(t)^3
    double A = P1.first  * P2.second;
    double B = P1.second * P2.first;

    // P1.first может обращать знаменатель в ноль
    if (P1.first == 0)
        P1.first = std::numeric_limits<double>::min();
    return (A - B) / pow(P1.first, 3); // возможно деление на ноль, необходимо обработать данную ситуацию
}

// вычисление длины кривой по области определения параметра t от t_begin до t_end:
// eps - точность eps вычисления интеграла;
// h   - шаг при вычислении конечной разности функции.
double Curve::get_length(double eps, double h) {

    double error = 1e10;       // начальное значение ошибки, заведомо большее входного значния eps
    unsigned long long n = 10; // начальное небольшое количество узлов сетки

    double simpson_integral;   // значение интеграла, посчитаное методом симпсона
    double old_value = Integrate_curve(n, h); // пердыдущее значение интеграла, вычисленное на сетке n

    // точность вычисления интеграла согласно правилу Рунге (teta = 15 для метода симпсона)
    while (error/15 > eps) {
        n *= 2; // удвоение узлов сетки
        simpson_integral = Integrate_curve(n, h);  // значение интеграла на удвоенной сетке

        error = abs(old_value - simpson_integral); // разность интегралов на сетках n и 2*n
        old_value = simpson_integral; // значение интеграла на данной итерации сохраняется
    }

    return simpson_integral;
}

// метод вычисления проекции заданной точки P на кривую с помощью перебора всех точек t из области определения с шагом h:
// P - проецируемая точка;
// eps - точность равенства нулю целевой (минимизируемой) функции;
// 1/h - количество анализируемых точек вдоль кривой
double Curve::get_projection(Point P, double eps, double h) {
    
    // в случае отсутсвия найденной точки проекции производится возврат NAN
    double projection = NAN;

    double t = t_begin;                  // начальное значение параметра t
    double dt = (t_end - t_begin) * h;   // величина инкремента параметра t
    double DeltaAngle;                   // угол между нормалью кривой в точке t и углом визирования кривой из точки P

    while (abs(t - t_end) > 2 * h) {     // пока не произойдет достижения значением параметра t конечного значения t_end 
        DeltaAngle = ScanFunction(t, P); // вычисление разности между углом нормали и углом визирования

        // досрочный выход из цикла производится при уменьшении разности между углом нормали и углом визирования до значения, меньшего eps,
        // либо при значении данной разности, отличной от 180гр на величину меньшую eps (что также свидетельствует об равенстве коэффициентов наклона)
        if (abs(DeltaAngle) <= eps || (abs(DeltaAngle - PI) <= eps)) {
            projection = t; // возвращение из функции текущего параметра t
            break;
        }

        t += dt; // инкремент текущего значения параметра t
    }
    return projection;
}

// метод вычисления первой производной функции одной переменной
// t - параметр кривой
// h - величина приращения при вычислении конечной разности
std::pair<double, double> Curve::first_derivative(double t, double h) {

    // Приближённое вычисление производных функции осуществляется с помощью подходящего набора коэффициентов: 
    // https://ru.wikipedia.org/wiki/Коэффициенты_формул_численного_дифференцирования

    Point P(0, 0);
    // если параметр t не выходит из-за границ области определения используются симметричные коэффициенты
    if ((t - 3*h) > t_begin && (t + 3*h) < t_end) 
        P = (1/280.*get_point(t - 4*h) - 4/105.*get_point(t - 3*h) + 1/5.*get_point(t - 2*h) - 4/5.*get_point(t - h)
            + 4/5.*get_point(t + h) - 1/5.*get_point(t + 2*h) + 4/105.*get_point(t + 3*h) - 1/280.*get_point(t + 4*h)) / h;
   
    // если параметр t выходит за левую границу области определения используются коэффициенты вперед
    else if ((t + 6*h) < t_end)
        P = (-49/20.*get_point(t) + 6.*get_point(t + h) - 15/2.*get_point(t + 2*h) + 20/3.*get_point(t + 3*h)
            - 15/4.*get_point(t + 4*h) + 6/5.*get_point(t + 5*h) - 1/6.*get_point(t + 6*h)) / h;

    // если параметр t выходит за правую границу области определения используются коэффициенты назад
    else if ((t - 6*h) > t_begin)
        P = (49/20.*get_point(t) - 6.*get_point(t - h) + 15/2.*get_point(t - 2*h) - 20/3.*get_point(t - 3*h)
            + 15/4.*get_point(t - 4*h) - 6/5.*get_point(t - 5*h) + 1/6.*get_point(t - 6*h)) / h;
    else
        P = (1/280.*get_point(t - 4*h) - 4/105.*get_point(t - 3*h) + 1/5.*get_point(t - 2*h) - 4/5.*get_point(t - h)
            + 4/5.*get_point(t + h) - 1/5.*get_point(t + 2*h) + 4/105.*get_point(t + 3*h) - 1/280.*get_point(t + 4*h)) / h;

    return std::make_pair(P.x1, P.x2);
}

// метод вычисления второй производной функции одной переменной
// t - параметр кривой
// h - величина приращения при вычислении конечной разности
std::pair<double, double> Curve::second_derivative(double t, double h) {

    // Вычисление второй производной осуществляется аналогично первой производной с помощью подходящего набора коэффициентов: 
    // https://ru.wikipedia.org/wiki/Коэффициенты_формул_численного_дифференцирования

    Point P = (-1/560.*get_point(t - 4*h) + 8/315.*get_point(t - 3*h) - 1/5.*get_point(t - 2*h) + 8/5.*get_point(t - h) - 205/72.*get_point(t)
        + 8/5.*get_point(t + h) - 1/5.*get_point(t + 2*h) + 8/315.*get_point(t + 3*h) - 1/560.*get_point(t + 4*h)) / h / h;
    
    return std::make_pair(P.x1, P.x2);
}

// Вычисление интеграла от sqrt(x'(t)^2 + y'(t)^2) по всей области определения параметра t (от t_begin до t_end).
// Значение данного интерала равняется длине кривой.
// n - количество точек расчета интеграла.
// h - шаг при вычислении конечной разности функции.
double Curve::Integrate_curve(unsigned long long n, double h){

    double width = (t_end - t_begin) / n; // приращение параметра t
    double x1, x2;                        // начальная и конечная точки n-ого отрезка 
    std::pair<double, double> D1, D2, D3; // значения производных в точках x1, (x1 + x2)/2 и x2.

    double simpson_integral = 0;

    // разбиение всего диапазона интегрирования на n отрезков
    for (unsigned long long step = 0; step < n; step++) {
        x1 = t_begin + step * width;       
        x2 = t_begin + (step + 1) * width;

        // первая производная каждой функии в точке x1
        std::pair<double, double> D1 = first_derivative(x1, h);

        // первая производная каждой функии в точке 0.5 * (x1 + x2)
        std::pair<double, double> D2 = first_derivative(0.5*(x1 + x2), h);

        // первая производная каждой функии в точке x2
        std::pair<double, double> D3 = first_derivative(x2, h);

        // значения целевой функции в узлах сетки
        double f_1 = sqrt(pow(D1.first, 2) + pow(D1.second, 2));
        double f_2 = sqrt(pow(D2.first, 2) + pow(D2.second, 2));
        double f_3 = sqrt(pow(D3.first, 2) + pow(D3.second, 2));

        // аккумуляция текущего результата интегрирования на отрезке [x1,x2]
        simpson_integral += abs(x2 - x1) / 6.0 * (f_1 + 4.0*f_2 + f_3);
    }

    // возврат вычисленного интеграла
    return simpson_integral;
}

// вычисление угла визирования из точки P на точку кривой, соответсвующей параметру t
double Curve::SightAngle(double t, Point P) {
    // получение точки кривой, соответсвующей заданному параметру t
    Point T = get_point(t);

    // возврат значения угла между точкой визирования P и точкой кривой T
    return atan( (P.x2 - T.x2) / (P.x1 - T.x1) );
}

// вычисление разности между уголом визирования из точки P на точку кривой, соответсвующей параметру t,
// и нормалью кривой в точке t; h - шаг при вычислении конечной разности функции. 
double Curve::ScanFunction(double t, Point P, double h) {
    double Sight = SightAngle(t, P);                        // угол визирования на кривую в точке t
    std::pair<double, double> der = first_derivative(t, h); // первая производная кривой в точке t
    double NormalAngle = atan(-der.first / der.second);     // угол вектора нормали к кривой в точке t

    // возврат разности углов
    return abs(NormalAngle - Sight); 
}

// метод, возвращающий наименование кривой.
std::string Curve::get_name() {
    return "general curve";
}