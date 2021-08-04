#ifndef CircuitCurve_H
#define CircuitCurve_H

#include "EllipsCurve.h" 

// класс, реализующий окружность. наследуется от эллипса, значения полуосей в этом случае равны.
class CircuitCurve : public  EllipsCurve {

public:
	CircuitCurve(type_of_coordinate_system CS, double t_begin_, double t_end_, double a_, double w_, double phi_) :
		EllipsCurve(CS, t_begin_, t_end_, a_, a_, w_, phi_) {};
	std::string get_name() {
		return "circuit";
	}
};

#endif


