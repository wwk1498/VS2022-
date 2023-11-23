#include<iostream>
#include<vector>
#include<algorithm>//标准算法头文件
using namespace std;
class person {
public:
	string m_name;
	int m_id;
	person(string n,int id) {
		this->m_id = id;
		this->m_name = n;
	}
};

void test01() {
	vector<person*> v;

	person n1("www", 1);
	person n2("wwwe", 2);
	person n3("wwwt", 3);
	person n4("wwwu", 4);

	v.push_back(&n1);
	v.push_back(&n2);
	v.push_back(&n3);
	v.push_back(&n4);

	for (vector<person*>::iterator it = v.begin(); it != v.end(); it++) {
		cout << (*it)->m_id << "  " << (*it)->m_name << endl;
	}

}


void test02() {
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;

	for (int i = 0; i < 10; i++) {
		v1.push_back(i+1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}

	vector<vector<int>> v;

	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
			cout << *vit << " " ;
		}
		cout << endl;
	}


}






void printvet(int val) {
	cout << val << endl;
}
void test() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	vector<int>::iterator itbegin = v.begin();
	vector<int>::iterator itend = v.end();

	/*while (itbegin != itend) {
		cout << *itbegin << endl;
		itbegin++;
	}*/
	for_each(v.begin(), v.end(), printvet);

}
int main() {
	test02();
	system("pause");
	return 0;
}