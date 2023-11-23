#include<iostream>
using namespace std;
#define MAX 1000
struct persion {
	string name;
	string  gender;
	int age;
	string phone;
	string address;
};

struct addressBooks {
	struct persion persionaeey[MAX];
	int numbers;
};


//菜单界面
void showMenu() {
	cout << "*******************************" << endl;
	cout << "*******1、添加联系人*******" << endl;
	cout << "*******2、显示联系人*******" << endl;
	cout << "*******3、删除联系人*******" << endl;
	cout << "*******4、查找联系人*******" << endl;
	cout << "*******5、修改联系人*******" << endl;
	cout << "*******6、清空联系人*******" << endl;
	cout << "*******0、退出通讯录*******" << endl;
	cout << "*******************************" << endl;

}



//添加联系人
void add(struct addressBooks* tp) {
	if (tp->numbers >= MAX) {
		cout << "联系人已满！" << endl;
		return;
	}
	else {
		cout << "请输入联系人姓名：" << endl;
		string name;
		cin >> name;
		tp->persionaeey[tp->numbers].name = name;

		cout << "请输入联系人性别：" << endl;
		cout << "1  男" << endl;
		cout << "2  女" << endl;

		while (true) {
			int gender1;
			cin >> gender1;
			if (gender1 == 1) {
				tp->persionaeey[tp->numbers].gender = "男";
				break;
			}
			else if (gender1 == 2) {
				tp->persionaeey[tp->numbers].gender = "女";
				break;
			}
			else {
				cout << "输入错误，请重新输入！" << endl;
			}
		}

		cout << "请输入联系人年龄：" << endl;
		int age;
		cin >> age;
		tp->persionaeey[tp->numbers].age = age;

		cout << "请输入联系人电话：" << endl;
		string phone;
		cin >> phone;
		tp->persionaeey[tp->numbers].phone = phone;

		cout << "请输入联系人地址：" << endl;
		string address;
		cin >> address;
		tp->persionaeey[tp->numbers].address = address;
	}

	(tp->numbers)++;
	cout << "添加成功！" << endl;
	system("pause");
	system("cls");//清屏
	return;

}
//显示联系人
void views(struct addressBooks* tp) {
	if (tp->numbers != 0) {
		for (int i = 0; i < tp->numbers; i++) {
			cout << "姓名：" << tp->persionaeey[i].name << "\t";
			cout << "性别：" << tp->persionaeey[i].gender << "\t";
			cout << "年龄：" << tp->persionaeey[i].age << "\t";
			cout << "电话：" << tp->persionaeey[i].phone << "\t";
			cout << "地址：" << tp->persionaeey[i].address << endl;
		}
	}
	else {
		cout << "暂无联系人" << endl;
	}
	system("pause");
	system("cls");//清屏
	return;

}
//删除联系人
void deletes(struct addressBooks* tp) {
	struct addressBooks mp;
	int temp = -1;
	if (tp->numbers != 0) {
		while (true) {

			cout << "请输入要删除的联系人姓名：" << endl;
			string name;
			cin >> name;
			for (int i = 0; i < tp->numbers; i++) {
				if (tp->persionaeey[i].name == name) {
					temp = i;
				}
			}

			if (temp != -1) {

				if (temp != tp->numbers - 1) {
					for (int j = temp; j < tp->numbers - 1; j++) {
						tp->persionaeey[j] = tp->persionaeey[j + 1];
					}
					(tp->numbers)--;
				}
				else {
					for (int f = 0; f < temp; f++) {
						mp.persionaeey[f] = tp->persionaeey[f];
					}
					mp.numbers = (tp->numbers) - 1;
					*tp = mp;
				}
				cout << "删除成功！" << endl;
				break;
			}
			else {
				cout << "查无此人" << endl;
			}
		}
	}
	else {
		cout << "暂无联系人可删除！" << endl;
	}
	system("pause");
	system("cls");//清屏
	return;
}
//查找联系人
void selectPersion(struct addressBooks* tp) {
	cout << "请输入要查找的联系人姓名：" << endl;
	int flag = -1;
	string name;
	cin >> name;
	for (int i = 0; i < tp->numbers; i++) {
		if (tp->persionaeey[i].name == name) {
			flag = 0;
			cout << "姓名：" << tp->persionaeey[i].name << "\t";
			cout << "性别：" << tp->persionaeey[i].gender << "\t";
			cout << "年龄：" << tp->persionaeey[i].age << "\t";
			cout << "电话：" << tp->persionaeey[i].phone << "\t";
			cout << "地址：" << tp->persionaeey[i].address << endl;
			break;
		}

	}
	if (flag == -1) {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");//清屏
	return;
}
//修改联系人
void update(struct addressBooks* tp) {
	cout << "请输入要修改的联系人姓名：" << endl;
	int flag = -1;
	string name;
	cin >> name;
	for (int i = 0; i < tp->numbers; i++) {
		if (tp->persionaeey[i].name == name) {
			flag = 0;
			cout << "请输入联系人姓名：" << endl;
			string name1;
			cin >> name1;
			tp->persionaeey[i].name = name1;

			cout << "请输入联系人性别：" << endl;
			cout << "1  男" << endl;
			cout << "2  女" << endl;

			while (true) {
				int gender1;
				cin >> gender1;
				if (gender1 == 1) {
					tp->persionaeey[i].gender = "男";
					break;
				}
				else if (gender1 == 2) {
					tp->persionaeey[i].gender = "女";
					break;
				}
				else {
					cout << "输入错误，请重新输入！" << endl;
				}
			}

			cout << "请输入联系人年龄：" << endl;
			int age;
			cin >> age;
			tp->persionaeey[i].age = age;

			cout << "请输入联系人电话：" << endl;
			string phone;
			cin >> phone;
			tp->persionaeey[i].phone = phone;

			cout << "请输入联系人地址：" << endl;
			string address;
			cin >> address;
			tp->persionaeey[i].address = address;

			cout << "修改成功！" << endl;
			break;
		}
	}
	if (flag == -1) {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");//清屏
	return;
}

//清空联系人
void qingKong(struct addressBooks* tp) {
	tp->numbers = 0;
	cout << "已清空联系人信息！" << endl;
	system("pause");
	system("cls");//清屏
	return;
}
//退出
void exitX() {
	system("pause");
	system("cls");//清屏
	return;
}
//出错
void defau() {
	system("exit");
	system("pause");
	system("cls");//清屏
	return;
}

int main(void) {

	struct addressBooks pers;
	pers.numbers = 0;
	while (true) {
		//展示菜单
		showMenu();

		int select;
		cout << "请选择对应功能：" << endl;
		cin >> select;
		if (select == 1) {
			add(&pers);
		}
		else if (select == 2) {
			views(&pers);
		}
		else if (select == 3) {
			deletes(&pers);
		}
		else if (select == 4) {
			selectPersion(&pers);
		}
		else if (select == 5) {
			update(&pers);
		}
		else if (select == 6) {
			qingKong(&pers);
		}
		else if (select == 0) {
			cout << "欢迎下次使用！" << endl;
			system("pause");
			//system("cls");//清屏
			return 0;
			break;
		}
		else {
			cout << "输入错误，请重新输入！" << endl;
			system("pause");
			system("cls");
		}
	}
	return 0;
}