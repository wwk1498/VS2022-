#include<iostream>
#include<fstream>//头文件
#include<string>
using namespace std;


//读写文件操作
void test() {
	ofstream ofs;//要写的文件对象
	ifstream ifs;//要读的文件对象

	ofs.open("E:\\Users\\ASUS\\Desktop\\test.txt",ios::out);//指定打开方式
	ifs.open("E:\\Users\\ASUS\\Desktop\\test.txt", ios::in);//指定打开方式


	//写内容
	ofs << "姓名：张三" << endl;
	ofs << "姓别：男" << endl;
	ofs << "年龄：12" << endl;
	
	//判断是否读取失败
	if (!ifs.is_open()) {
		cout << "打开失败！" << endl;
		return;
	}

	//读取方式
	string buf;
	while (getline(ifs, buf)) {//从输入流对象ifs中逐行读取文件内容，并将每行内容打印到控制台上
		cout << buf << endl;
	}
	
	//关闭文件
	ofs.close();
	ifs.close();
}

int main() {
	test();
	system("pause");
	return 0;
}