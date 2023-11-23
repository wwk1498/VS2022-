#include<iostream>
#include<fstream>
using namespace std;
//二进制读写文件
class person {
public:
	char m_name[64];
	int m_age;
};

/*void test() {
	ofstream ofs("E:\\Users\\ASUS\\Desktop\\test.txt", ios::out | ios::binary);//创建输出流并打开指定位置的文件

	person p = { "zahngs", 17 };
	ofs.write((const char*)&p, sizeof(person));//写文件
	ofs.close();//关闭文件
}*/
void test01() {
	ifstream ifs("E:\\Users\\ASUS\\Desktop\\test.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "文件打开失败！" << endl;
		return;
	}
	person p;
	ifs.read((char*)&p, sizeof(person));
	cout << "姓名：" << p.m_name << "年龄：" << p.m_age << endl;
	ifs.close();
}


int main() {
	//test();
	test01();
	system("pause");
	return 0;
}