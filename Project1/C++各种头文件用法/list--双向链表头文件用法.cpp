#include<iostream>
#include <list>//����ͷ�ļ�
using namespace std;

bool compare(int a, int b) {
	// �Զ���ȽϺ��������վ���ֵ��������
	return std::abs(a) < std::abs(b);
}

int main() {

	//1.�����������ʹ��std::listģ���ഴ��һ��������󣬲�ָ��Ԫ������
	list<int> myList;  // ����һ���洢 int ����Ԫ�ص��������


	//������ĩβ����Ԫ�ء�
	myList.push_back(10);


	//������ͷ����Ԫ�ء�
	myList.push_front(20);


	//ɾ������ĩβ��Ԫ�ء�
	myList.push_back(10);
	myList.push_back(20);
	myList.pop_back();


	//ɾ������ͷ��Ԫ�ء�
	myList.push_back(10);
	myList.push_back(20);
	myList.pop_front();

	//��ָ��λ�ò���Ԫ�ء�
	list<int>::iterator it = myList.begin();
	myList.insert(it, 30);  // �ڿ�ͷ����Ԫ��

	//ɾ��ָ��λ�û�Χ�ڵ�Ԫ�ء�
	list<int>::iterator it = myList.begin();
	myList.erase(it);  // ɾ��������ָ���Ԫ��

	//����������Ԫ�ص�������
	myList.push_back(10);
	myList.push_back(20);
	cout << myList.size();  // ��� 2

	//��������Ƿ�Ϊ�ա�
	if (myList.empty()) {
		cout << "����Ϊ��";
	}

	//��������ĵ�һ��Ԫ��
	myList.push_back(10);
	cout << myList.front();  // ��� 10


	//������������һ��Ԫ�ء�
	myList.push_back(10);
	myList.push_back(20);
	cout << myList.back(); // ��� 20

	//��������е�����Ԫ��
	myList.push_back(10);
	myList.clear();

	//��������ĳ��÷�����ʹ�õ�������iterator��
	myList.push_back(10);
	myList.push_back(20);
	for (list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
		cout << *it << " ";  // ��������е�Ԫ��
	}


	//sort()�������ڶ����������������Ĭ��ʹ��Ԫ�ص�С�ڱȽ������ < ��������
	myList.push_back(10);
	myList.push_back(30);
	myList.push_back(20);

	myList.sort();  // �������������

	for (const auto& element : myList) {
		cout << element << " ";
	}
	// �����10 20 30


	
	//�����Ҫʹ���Զ���ıȽϺ����������򣬿����ṩһ���Զ���ıȽϺ�����Ϊsort()�����Ĳ�����
	list<int> myList;
	myList.push_back(-10);
	myList.push_back(30);
	myList.push_back(-20);

	myList.sort(compare);  // ʹ���Զ���ȽϺ����������������

	for (const auto& element : myList) {
		cout << element << " ";
	}
	// �����-10 -20 30



	//reverse()�������ڽ������е�Ԫ�ط�ת��
	myList.push_back(10);
	myList.push_back(20);
	myList.push_back(30);

	myList.reverse();  // ��ת�����е�Ԫ��

	for (const auto& element : myList) {
		cout << element << " ";
	}
	// �����30 20 10



	system("pause");
	return 0;
}
