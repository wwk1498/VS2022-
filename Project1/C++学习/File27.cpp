#include<iostream>
#include<fstream>
using namespace std;
//�����ƶ�д�ļ�
class person {
public:
	char m_name[64];
	int m_age;
};

/*void test() {
	ofstream ofs("E:\\Users\\ASUS\\Desktop\\test.txt", ios::out | ios::binary);//�������������ָ��λ�õ��ļ�

	person p = { "zahngs", 17 };
	ofs.write((const char*)&p, sizeof(person));//д�ļ�
	ofs.close();//�ر��ļ�
}*/
void test01() {
	ifstream ifs("E:\\Users\\ASUS\\Desktop\\test.txt", ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	person p;
	ifs.read((char*)&p, sizeof(person));
	cout << "������" << p.m_name << "���䣺" << p.m_age << endl;
	ifs.close();
}


int main() {
	//test();
	test01();
	system("pause");
	return 0;
}