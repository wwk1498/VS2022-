#include<iostream>
#include<fstream>//ͷ�ļ�
#include<string>
using namespace std;


//��д�ļ�����
void test() {
	ofstream ofs;//Ҫд���ļ�����
	ifstream ifs;//Ҫ�����ļ�����

	ofs.open("E:\\Users\\ASUS\\Desktop\\test.txt",ios::out);//ָ���򿪷�ʽ
	ifs.open("E:\\Users\\ASUS\\Desktop\\test.txt", ios::in);//ָ���򿪷�ʽ


	//д����
	ofs << "����������" << endl;
	ofs << "�ձ���" << endl;
	ofs << "���䣺12" << endl;
	
	//�ж��Ƿ��ȡʧ��
	if (!ifs.is_open()) {
		cout << "��ʧ�ܣ�" << endl;
		return;
	}

	//��ȡ��ʽ
	string buf;
	while (getline(ifs, buf)) {//������������ifs�����ж�ȡ�ļ����ݣ�����ÿ�����ݴ�ӡ������̨��
		cout << buf << endl;
	}
	
	//�ر��ļ�
	ofs.close();
	ifs.close();
}

int main() {
	test();
	system("pause");
	return 0;
}