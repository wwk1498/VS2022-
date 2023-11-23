#include "circle.h"

void Circle::setR(int r) {
	R = r;
}

void Circle::setPoint(Point pot) {
	point = pot;
}

int  Circle::getR() {
	return R;
}

Point  Circle::getPoint() {
	return point;
}
