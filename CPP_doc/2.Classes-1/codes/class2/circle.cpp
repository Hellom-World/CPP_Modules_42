#include "circle.h"

	Circle::Circle() {
		radius = 0.0;
		x	=	0;
		y = 0;
	}
	Circle::Circle(float rr, int xx, int yy) {
		set_radius(rr);
		set_origin(xx, yy);
	}

	float Circle::area() {
		return radius*radius*3.141592;
	}

	float Circle::diameter() {
		return radius*2;
	}

	void Circle::set_radius(float rr) {
		if (rr > 0)
			radius = rr;
		else
			radius = 0;
	}

	void Circle::set_origin(int xx, int yy) {
		x = xx;
		y = yy;
	}

	float Circle::get_radius() {
		return radius;
	}
	
	void Circle::print() {
		std::cout << "{radius= " << radius << ", x = " << x << ", y = " << y <<"}";
	}