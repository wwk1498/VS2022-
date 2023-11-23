#pragma once
#include<iostream>
#include "point.h"
using namespace std;

class Circle {
private:
	int R;
	Point point;
public:
	void setR(int r);

	void setPoint(Point pot);

	int  getR();

	Point  getPoint();

};
