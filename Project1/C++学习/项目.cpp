#include<iostream>
using namespace std;
#include "circle.h"
#include "point.h"

/*class Point {

private:
	int X;
	int Y;

public:
	void setX(int x) {
		X = x;
	}

	void setY(int y) {
		Y = y;
	}

	int getX() {
		return X;
	}

	int getY() {
		return Y;
	}
};



class Circle {

private:
	int R;
	Point point;
public:

	void setR(int r) {
		R= r;
	}

	void setPoint(Point pot) {
		point = pot;
	}

	int  getR() {
		return R;
	}

	Point  getPoint() {
		return point;
	}
};
*/


void  pandaun(Circle circle, Point point) {
	int s1 = (circle.getPoint().getX() - point.getX()) * (circle.getPoint().getX() - point.getX())+ (circle.getPoint().getY() - point.getY()) * (circle.getPoint().getY() - point.getY());
	int s2 = circle.getR() * circle.getR();

	if (s1 == s2) {
		cout << "ÉÏ" << endl;
	}
	else if (s1 > s2) {
		cout << "Íâ" << endl;
	}
	else if (s1 < s2) {
		cout << "ÄÚ" << endl;
	}


}


int main() {

	Circle circle;
	circle.setR(4);
	Point point;
	point.setX(21);
	point.setY(40);
	circle.setPoint(point);


	Point point1;
	point1.setX(2);
	point1.setY(4);

	pandaun(circle, point1);

	return 0;
}