#include<iostream>
using namespace std;


class Point {

public:
	int a;
	int b;
	int c;

	Point() {
		cout << "�޲�qq" << endl;
	}

	/*Point(int A, int B, int C) {

		a = A;
		b = B;
		c = C;

		//cout << "�в�qq" << endl;
	}*/
	Point(int A, int B, int C) : a(A), b(B), c(C) {

	}

	/*Point(const Point& sf) {
		k = sf.k;
		heigh=new int(*sf.heigh);
		cout << "����qq" << endl;
	}*/
	    

	/*~Point() {
		if (heigh != NULL) {
			delete heigh;
			heigh = NULL;
		}
		cout << "����ww" << endl;
	}*/

	
};


void sa() {
	Point p(56,7,8);
	cout << p.a <<"   " << p.b << "   " << p.c << endl;
}

//void saq() {

	//Point y = sa();
	//cout << (int*)&y << endl;
//}

int main() {

     //Point ps;
	
	sa();
	//saq();
	//cout << "11" << endl;
	

	system("pause");
	//system("cls");
	return 0;
}