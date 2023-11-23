#include<iostream>
using namespace std;


class Point {

public:
	int a;
	int b;
	int c;

	Point() {
		cout << "无参qq" << endl;
	}

	/*Point(int A, int B, int C) {

		a = A;
		b = B;
		c = C;

		//cout << "有参qq" << endl;
	}*/
	Point(int A, int B, int C) : a(A), b(B), c(C) {

	}

	/*Point(const Point& sf) {
		k = sf.k;
		heigh=new int(*sf.heigh);
		cout << "拷贝qq" << endl;
	}*/
	    

	/*~Point() {
		if (heigh != NULL) {
			delete heigh;
			heigh = NULL;
		}
		cout << "析构ww" << endl;
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