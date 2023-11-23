/*
* 哈希表:给每份数据分配一个编号，放入表格（数组）
建立编号与表格的索引关系，将来就可以通过编号快速查找数据

1.理想情况编号唯一，数组能能容纳所有数据
2.现实是不能说为了容纳所有数据造一个超大的数组，编号也有可能重复

解决:
1.有限长度的数组，以“拉链”方式存储数据
2.允许编号适当重复，通过数据自身来进行区分

*/

/*
* Hash算法是将任意对象，分配一个编号的过程，其中编号是一个有限范围内的数字
* 
* 哈希算法（Hash Algorithm）是一种将数据映射到固定长度的唯一值（哈希值）的算法。
  它将任意长度的数据转换为固定长度的哈希码，使得相同的输入始终产生相同的哈希值，
  并且不同的输入具有较大的概率产生不同的哈希值。

  原则：值相同的字符串生成相同的 hash 码，尽量让值不同的字符串生成不同的 hash 码

  对于  abc 
* 
*/


#include<iostream>
#include<functional>//hash函数调用头文件
#include<vector>//
#include<sstream>//数组元素转字符串头文件

using namespace std;

//哈希节点
typedef struct Entry {
	int hash;//哈希码
	string key;//键
	string value;//值
	struct Entry* next;
}Entry;

/*
* 求模运算替换为性能更好的位运算:
--前提:数组长度是2的n次方
--hash % 数组长度  等价于  hash &(数组长度 - 1）
*/


//哈希表
typedef struct HashTable {
	Entry** arr;//存储Entry*数据的指针
	int length;//数组长度
	int size;//元素个数
	double loadFactor = 0.75;//负载因子,当size > length*loadFactor时，扩充数组容量
}HashTable;

HashTable* w;//声明一个哈希表
hash<string> hasher;//创建一个哈希函数
vector<int> N;
stringstream ss;


//底层的字符串 hash算法：
int hasherm(string val) {
	int hash = 0;
	for (int i = 0; i < val.size(); i++) {
		char s = val[i];
		hash = (hash << 5) - hash + s;// hash = hash*31 + s;
	}
	return hash;
}


//扩大数组容量
void resizem(HashTable* table){
	Entry** p = new Entry * [(table->length) << 1];
	
	// 初始化指针数组
	for (int i = 0; i <(table->length) * 2; i++) {
		p[i] = NULL;
	}

	for (int j = 0; j < table->length; j++) {

		Entry* tep = table->arr[j];
		if (tep !=NULL) {
			/*
			* 数组长度是 2 的n次方
			* 拆分链表 移动到新数组
			* 一个链表最多拆分成两个
			*  hash & table->length == 0 为一组---放在原来位置
			*  hash & table->length != 0 为一组---放在新位置
			*/

			Entry* a = NULL;
			Entry* b = NULL;
			Entry* ahead = NULL;
			Entry* bhead = NULL;

			while (tep!=NULL) {
				if ((tep->hash & table->length) == 0) {
					//分配到a
					if (a != NULL) {
						a->next = tep;
					}
					else {
						ahead = tep;
					}
					a = tep;
				}
				else {
					//分配到b
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


//根据哈希码和键获取值
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



//向哈希表存入新的key 和 value ,如果key存在，就更新 value
void doput(int hash,string key, string val, HashTable* table) {
	if (table->length == table->size) {
		cout << "满了";
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

	//没找到节点
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

	table->size++;//元素个数增加

	//若数组元素个数大于负载因子的乘积，则扩大数组容量
	if (table->size > (int)(table->length*table->loadFactor)){
		resizem(table);
	}
	
}

void put1(string key,string val) {
	int hash = hasher(key);
	doput(hash, key,val,w);
}


//根据哈希码删除，返回删除的value
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

//测试链表长度
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

	//创建长度为16的哈希表
	int n = 16;
	
	w = new HashTable;
	w->arr = new Entry*[n]; // 分配内存空间
	w->size = 0;
	w->length = n;
	
	// 初始化指针数组
	for (int i = 0; i < n; i++) {
		w->arr[i] = NULL;
	}

	//prinfd();
	//cout << (int)(w->length * w->loadFactor) << endl;

	put1("zhang", "张三");//1
	put1( "Li", "李四");//1
	put1("wang", "王五");//2
	put1( "dao", "刀客");//2
	put1( "da", "刀");//2
	put1("dy", "刀");//2
	put1("dh", "刀");//2
	put1("dl", "刀");//2
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