#include<iostream>
using namespace std;
#include "person.cpp"
int main() {
	person<int, string> p(2, "yyyu");
	p.show();
	system("pause");
	return 0;
}