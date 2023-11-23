/*
"Set"��һ�����ݽṹ����ʾһ�黥����ͬ��Ԫ�صļ��ϡ�����ѭ���ϵ���ѧ����������е�ÿ��Ԫ����Ψһ�ģ�û���ظ���

Setͨ���ṩ�������ԣ�

Ψһ�ԣ�Set�е�Ԫ����Ψһ�ģ��������ظ�Ԫ�ء�
�����ԣ�Set��û���ض���˳��Ԫ�صĴ洢˳����Ҫ��
���ٲ��ң�Set֧�ֿ��ٵĲ��Ҳ��������Կ����ж�һ��Ԫ���Ƿ������Set�С�
�����ɾ����Set֧�ָ�Ч�Ĳ����ɾ��������

�ڱ�������У�Set��һ�ֳ��������ݽṹ���ͣ�����ͨ���ṩ�˶Լ��ϵĳ������������罫Ԫ�ز��뵽Set�С���Set��ɾ��Ԫ�ء�����Ԫ�ء��ж�Set�Ƿ�Ϊ�յȡ���C++�У�std::set��C++��׼����ʵ�ֵ�һ��Set������
Set��ʹ�ó����㷺�������������ȥ�ء����Ԫ���Ƿ���ڡ����㽻���Ͳ����Ȳ�����
*/

#include<iostream>
#include<set>
using namespace std;

int main() {

	//insert() : ���ڽ�Ԫ�ز���set�С�
	set<int> mySet;
	mySet.insert(10); //����Ԫ��10


	//erase() : ����ɾ��Ԫ�ء�
	set<int> mySet;
	mySet.erase(10); //ɾ��Ԫ��10


	//clear() : �������set�е�����Ԫ�ء�
	set<int> mySet;
	mySet.clear(); //���set


	//find() : ���ڲ���Ԫ�أ�����ָ���ҵ�Ԫ�صĵ����������û�ҵ��򷵻�end()��
	set<int> mySet;
	set<int>::iterator it = mySet.find(10); //����Ԫ��10
	if (it != mySet.end()) {
		//�ҵ���Ԫ��
	}
	else {
		//δ�ҵ�Ԫ��
	}


	//count() : ����ͳ��set���ض�Ԫ�صĸ��������� 0 ���� 1 ��--->��Ҫ�����ж�Ԫ���Ƿ������set��
	set<int> mySet;
	int count = mySet.count(10); //ͳ��Ԫ��10�ĸ���



	//size() : ���ڷ���set��Ԫ�صĸ�����
	set<int> mySet;
	int size = mySet.size(); //��ȡset��Ԫ�صĸ���



	//empty() : �����ж�set�Ƿ�Ϊ�գ�Ϊ�շ���true�����򷵻�false��
	set<int> mySet;
	bool isEmpty = mySet.empty(); //�ж�set�Ƿ�Ϊ��


	//begin() �� end() : ���ڻ�ȡָ��set��ͷ�ͽ�β�ĵ�������
	set<int> mySet;
	set<int>::iterator it = mySet.begin(); //��ȡ������ָ��set��ͷ
	set<int>::iterator end = mySet.end(); //��ȡ������ָ��set��β


	//lower_bound() �� upper_bound() : ���ڷ���ָ����ڵ��� / ����ĳ��ֵ�ĵ�һ��Ԫ�صĵ����������û��������Ԫ�أ��򷵻�end()��
	set<int> mySet;
	set<int>::iterator it = mySet.lower_bound(10); //���ش��ڵ���10�ĵ�һ��Ԫ�صĵ�����
	set<int>::iterator it = mySet.upper_bound(10); //���ش���10�ĵ�һ��Ԫ�صĵ�����



	//equal_range() : ���ڷ���ָ��ĳ��ֵ��Ԫ�ط�Χ�ĵ�������(equal_range)��
	set<int> mySet;
	pair<set<int>::iterator, set<int>::iterator> range = mySet.equal_range(10); //����ָ��ֵΪ10��Ԫ�ط�Χ�ĵ�������
	set<int>::iterator lower = range.first; //����ָ��Χ�ĵ�һ��Ԫ�صĵ�����
	set<int>::iterator upper = range.second; //����ָ��Χ�����һ��Ԫ�ص���һ��λ�õĵ�����
	













	system("pause");
	return 0;
}