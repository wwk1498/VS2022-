#include<iostream>
#include<vector>
using namespace std;



int main() {

	/*
	* vector<pair<double, double>> k_r(n) ��һ��������һ����СΪ n �� pair<double, double> ���͵����� k_r��
	  pair<double, double> ��һ�����ڴ洢����ֵ�����������е�һ��ֵ�������� double���ڶ���ֵ������Ҳ�� double��
	  ����������£�k_r ��һ���洢�� n �� (double, double) ֵ������
	*/
	//����һ���洢һ��Ԫ�صĶ������СΪ10
	vector<pair<double, double>> k_r;
	//�������
	k_r.push_back(make_pair(1.4,2.7));//���ߣ�k_r.push_back({2.6,5.9});
	k_r.push_back({ 2.6,5.9 });


	//��ʼ������vectorԪ��Ϊ0
	vector<int> vec(5,0);//��СΪ5��ÿ��Ԫ�ض�Ϊ0

	//��ʼ����ά����vectorԪ��Ϊ0
	vector<vector<int>> vec(5, vector < int>(4,0));//��СΪ5��ÿ��Ԫ�ش�СΪ5��Ԫ�ص�Ԫ�صĴ�С��Ϊ4����ֵΪ0

	//push_back(): ��vectorβ�����һ��Ԫ��
	vector<int> vec;
	vec.push_back(10); // {10}
	vec.push_back(20); // {10, 20}

	//pop_back(): �Ƴ�vectorβ����һ��Ԫ�ء�
	vector<int> vec = { 10, 20, 30 };
	vec.pop_back(); // {10, 20}

	//size(): ���ص�ǰvector�е�Ԫ��������
	vector<int> vec = { 10, 20, 30 };
	int size = vec.size(); // 3

	//empty(): ���vector�Ƿ�Ϊ�գ����ز���ֵ��
	vector<int> vec = { 10, 20, 30 };
	bool isEmpty = vec.empty(); // false

	//clear(): ���vector�е�����Ԫ�ء�
	vector<int> vec = { 10, 20, 30 };
	vec.clear(); // {}

	//resize(): ����vector�Ĵ�С���������ӻ����Ԫ��������
	vector<int> vec = { 10, 20, 30 };
	vec.resize(5); // {10, 20, 30, 0, 0}
	vec.resize(2); // {10, 20}

	//at(): ����ָ��λ�õ�Ԫ�أ����б߽��顣
	vector<int> vec = { 10, 20, 30 };
	int element = vec.at(1); // 20

	//front(): ����vector�ĵ�һ��Ԫ�ء�
	vector<int> vec = { 10, 20, 30 };
	int firstElement = vec.front(); // 10

	//back(): ����vector�����һ��Ԫ�ء�
	vector<int> vec = { 10, 20, 30 };
	int lastElement = vec.back(); // 30

	//erase() : �Ƴ�ָ��λ�û�ָ����Χ��Ԫ�ء�
	vector<int> vec = { 10, 20, 30, 40, 50 };
	vec.erase(vec.begin() + 2); // {10, 20, 40, 50}
	vec.erase(vec.begin() + 1, vec.begin() + 3); // {10, 50}

	//insert(): ��ָ��λ�ò���һ������Ԫ�ء�
	vector<int> vec = { 10, 20, 30 };
	vec.insert(vec.begin() + 1, 15); // {10, 15, 20, 30}
	vec.insert(vec.begin() + 2, 2, 25); // {10, 15, 25, 25, 20, 30}

	//����ָ����Ԫ�صĵ�����������
	vector<int> vec = { 10, 20, 30 };
	auto it = find(vec.begin(),vec.end(),20);
	if (it!=vec.end()) {
		vec.erase(it);//�Ƴ���һ��Ԫ�غ󣬵ڶ���Ԫ�ػ���ǰ�ƶ����һ��Ԫ�ص�λ�ã�����������Ϊ0
	}

	system("pause");
	return 0;
}