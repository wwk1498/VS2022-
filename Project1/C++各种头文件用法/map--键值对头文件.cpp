/*
map��C++��׼���е�һ���������������Լ�-ֵ��(key-value pairs)����ʽ�洢���ݡ���map�У�ÿ��������Ψһ�ģ��Ҽ���ֵ��һһ��Ӧ�ġ�
map���Ը��ݼ���ֵ���п��ٵĲ��ҡ������ɾ�����������ڲ�ʹ�ú����(Red-Black Tree)��Ϊ���ݽṹ����֤��Ԫ�ص������ԣ����Ҹ��ֲ�����ƽ��ʱ�临�Ӷ�ΪO(logN)������N��map�е�Ԫ��������
ʹ��map����ʵ�ָ�Ч�ļ�ֵ���Һ������ܡ�����������Ҫ���ٲ��ҡ������ɾ����ֵ�Եĳ����������ֵ䡢�����ȡ�

������map���ص㣺

��Ψһ��ÿ������map��ֻ�ܴ���һ�Ρ�
�Զ�����map����ݼ���ֵ�Զ��������򣬱���Ԫ�ص������ԡ�
�����ʵ�֣�map�ڲ�ʹ�ú�������ݽṹ���洢Ԫ�أ���֤�˸�Ч�Ĳ��ҺͲ��������
��̬��С��map���Զ�̬�����洢�ռ��С��������Ҫ�Զ�������ͷ��ڴ档

*/

#include<iostream>
#include<map>
using namespace std;


int main() {
	

	//����Ԫ�أ�map::insert()  
	map<int, string> myMap;
	myMap.insert(make_pair(1, "v")); // ����һ�Լ�ֵ��, make_pair(1, "v")--> ����������һ������ 1��"v" �� pair������ʱ����



	//����Ԫ�أ�map::operator[]
	map<int, string> myMap;
	
	myMap[1] = "e"; // ͨ�������ʻ�ֵԪ��


	//ɾ��Ԫ�أ�map::erase()
	map<int, string> myMap;
	myMap.erase(2); // ɾ��ָ������Ԫ��


	//����Ԫ�أ�map::find()
	map<int, string> myMap;
	auto it = myMap.find(3); // ����ָ������Ԫ�أ�it��map�ĵ�����
	if (it != myMap.end()) {
		// Ԫ�ش���
	}
	else {
		// Ԫ�ز�����
	}



	//��ȡԪ�ظ�����map::size()
	map<int, string> myMap;
	cout << "Ԫ�ظ�����" << myMap.size() <<endl;



	//���map��map::clear()
	map<int, string> myMap;
	myMap.clear(); // �������Ԫ��



	//����map��ʹ�õ�����
	map<int, string> myMap;
	for (auto it = myMap.begin(); it != myMap.end(); ++it) {
		// ��������Ԫ��
		int key = it->first;//����it��Ӧ�ļ�
		string value = it->second;//����it��Ӧ��ֵ
	}

	system("pause");
	return 0;
}