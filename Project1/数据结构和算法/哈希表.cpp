/*
* ��ϣ��:��ÿ�����ݷ���һ����ţ����������飩
������������������ϵ�������Ϳ���ͨ����ſ��ٲ�������

1.����������Ψһ����������������������
2.��ʵ�ǲ���˵Ϊ����������������һ����������飬���Ҳ�п����ظ�

���:
1.���޳��ȵ����飬�ԡ���������ʽ�洢����
2.�������ʵ��ظ���ͨ��������������������

*/

/*
* Hash�㷨�ǽ�������󣬷���һ����ŵĹ��̣����б����һ�����޷�Χ�ڵ�����
* 
* ��ϣ�㷨��Hash Algorithm����һ�ֽ�����ӳ�䵽�̶����ȵ�Ψһֵ����ϣֵ�����㷨��
  �������ⳤ�ȵ�����ת��Ϊ�̶����ȵĹ�ϣ�룬ʹ����ͬ������ʼ�ղ�����ͬ�Ĺ�ϣֵ��
  ���Ҳ�ͬ��������нϴ�ĸ��ʲ�����ͬ�Ĺ�ϣֵ��

  ԭ��ֵ��ͬ���ַ���������ͬ�� hash �룬������ֵ��ͬ���ַ������ɲ�ͬ�� hash ��

  ����  abc 
* 
*/


#include<iostream>
#include<functional>//hash��������ͷ�ļ�
#include<vector>//
#include<sstream>//����Ԫ��ת�ַ���ͷ�ļ�

using namespace std;

//��ϣ�ڵ�
typedef struct Entry {
	int hash;//��ϣ��
	string key;//��
	string value;//ֵ
	struct Entry* next;
}Entry;

/*
* ��ģ�����滻Ϊ���ܸ��õ�λ����:
--ǰ��:���鳤����2��n�η�
--hash % ���鳤��  �ȼ���  hash &(���鳤�� - 1��
*/


//��ϣ��
typedef struct HashTable {
	Entry** arr;//�洢Entry*���ݵ�ָ��
	int length;//���鳤��
	int size;//Ԫ�ظ���
	double loadFactor = 0.75;//��������,��size > length*loadFactorʱ��������������
}HashTable;

HashTable* w;//����һ����ϣ��
hash<string> hasher;//����һ����ϣ����
vector<int> N;
stringstream ss;


//�ײ���ַ��� hash�㷨��
int hasherm(string val) {
	int hash = 0;
	for (int i = 0; i < val.size(); i++) {
		char s = val[i];
		hash = (hash << 5) - hash + s;// hash = hash*31 + s;
	}
	return hash;
}


//������������
void resizem(HashTable* table){
	Entry** p = new Entry * [(table->length) << 1];
	
	// ��ʼ��ָ������
	for (int i = 0; i <(table->length) * 2; i++) {
		p[i] = NULL;
	}

	for (int j = 0; j < table->length; j++) {

		Entry* tep = table->arr[j];
		if (tep !=NULL) {
			/*
			* ���鳤���� 2 ��n�η�
			* ������� �ƶ���������
			* һ����������ֳ�����
			*  hash & table->length == 0 Ϊһ��---����ԭ��λ��
			*  hash & table->length != 0 Ϊһ��---������λ��
			*/

			Entry* a = NULL;
			Entry* b = NULL;
			Entry* ahead = NULL;
			Entry* bhead = NULL;

			while (tep!=NULL) {
				if ((tep->hash & table->length) == 0) {
					//���䵽a
					if (a != NULL) {
						a->next = tep;
					}
					else {
						ahead = tep;
					}
					a = tep;
				}
				else {
					//���䵽b
					if (b != NULL) {
						b->next = tep;
					}
					else {
						bhead = tep;
					}
					b = tep;
				}
				tep = tep->next;
			}

			a->next = NULL;
			p[j] = a;
			b->next = NULL;
			p[j + table->length] = b;
		}
	}
	w->arr = p;
	w->length = (table->length) * 2;
}


//���ݹ�ϣ��ͼ���ȡֵ
string doget(int hash,string key, HashTable*table) {
	int index = hash & (table->length - 1);
	Entry* tep = table->arr[index];
	while(tep!=NULL) {
		if (tep->key == key) {
			return tep->value;
		}
		tep = tep->next;
	}
	return "NULL";
}


string get1(string key) {
	int hash = hasher(key);
	return doget(hash,key,w);
}



//���ϣ������µ�key �� value ,���key���ڣ��͸��� value
void doput(int hash,string key, string val, HashTable* table) {
	if (table->length == table->size) {
		cout << "����";
		return;
	}

	int index = hash & (table->length - 1);
	
	Entry* tep= table->arr[index]; 
	
	Entry* parent=NULL;
	while (tep!=NULL) {
		if (tep->key == key) {
			tep->value = val;
			return;
		}
		parent = tep;
		tep = tep->next;
	}

	//û�ҵ��ڵ�
	Entry* newentry = new Entry;
	newentry->hash = hash;
	newentry->key = key;
	newentry->value = val;
	newentry->next = NULL;
	
	if (parent!=NULL) {
		parent->next = newentry;
	}
	else {
		table->arr[index] = newentry;
	}

	table->size++;//Ԫ�ظ�������

	//������Ԫ�ظ������ڸ������ӵĳ˻�����������������
	if (table->size > (int)(table->length*table->loadFactor)){
		resizem(table);
	}
	
}

void put1(string key,string val) {
	int hash = hasher(key);
	doput(hash, key,val,w);
}


//���ݹ�ϣ��ɾ��������ɾ����value
string doremove(int hash,string key, HashTable* table) {
	int index = hash & (table->length - 1);
	Entry* tep = table->arr[index];
	Entry* parent = NULL;
	while (tep != NULL) {
		if (tep->key==key) {
			if (tep->next==NULL) {
				table->arr[index] = NULL;
				return tep->value;
			}
			parent->next = tep->next;
			table->size--;
			return tep->value;
		}
		parent = tep;
		tep = tep->next;
	}
	return "NULL";
}

string remove1(string key) {
	int hash = hasher(key);
	return doremove(hash, key,w);
}

//����������
void prinfd() {
	
	for (int i = 0; i < w->length; i++) {
		Entry* p = w->arr[i];
		N.push_back(0);
		while (p!=NULL) {
			N[i]++;
			p = p->next;
		}
		ss << to_string(N[i]);
	}

	string result = ss.str();
	cout << result <<" ";
}



int main() {

	//��������Ϊ16�Ĺ�ϣ��
	int n = 16;
	
	w = new HashTable;
	w->arr = new Entry*[n]; // �����ڴ�ռ�
	w->size = 0;
	w->length = n;
	
	// ��ʼ��ָ������
	for (int i = 0; i < n; i++) {
		w->arr[i] = NULL;
	}

	//prinfd();
	//cout << (int)(w->length * w->loadFactor) << endl;

	put1("zhang", "����");//1
	put1( "Li", "����");//1
	put1("wang", "����");//2
	put1( "dao", "����");//2
	put1( "da", "��");//2
	put1("dy", "��");//2
	put1("dh", "��");//2
	put1("dl", "��");//2
	prinfd();

	//cout << get1("zhang")<<endl;
	//cout << get1("wang") << endl;
	//cout << get1("xing") << endl;

	//cout << remove1( "dao") << endl;
	
	//cout<< get1( "dao") << endl;
	//cout << get1( "da" )<< endl;
	//cout<< get1( "aer") << endl;

	system("pause");
	return 0;
}