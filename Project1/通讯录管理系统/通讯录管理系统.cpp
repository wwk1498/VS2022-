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


//�˵�����
void showMenu() {
	cout << "*******************************" << endl;
	cout << "*******1�������ϵ��*******" << endl;
	cout << "*******2����ʾ��ϵ��*******" << endl;
	cout << "*******3��ɾ����ϵ��*******" << endl;
	cout << "*******4��������ϵ��*******" << endl;
	cout << "*******5���޸���ϵ��*******" << endl;
	cout << "*******6�������ϵ��*******" << endl;
	cout << "*******0���˳�ͨѶ¼*******" << endl;
	cout << "*******************************" << endl;

}



//�����ϵ��
void add(struct addressBooks* tp) {
	if (tp->numbers >= MAX) {
		cout << "��ϵ��������" << endl;
		return;
	}
	else {
		cout << "��������ϵ��������" << endl;
		string name;
		cin >> name;
		tp->persionaeey[tp->numbers].name = name;

		cout << "��������ϵ���Ա�" << endl;
		cout << "1  ��" << endl;
		cout << "2  Ů" << endl;

		while (true) {
			int gender1;
			cin >> gender1;
			if (gender1 == 1) {
				tp->persionaeey[tp->numbers].gender = "��";
				break;
			}
			else if (gender1 == 2) {
				tp->persionaeey[tp->numbers].gender = "Ů";
				break;
			}
			else {
				cout << "����������������룡" << endl;
			}
		}

		cout << "��������ϵ�����䣺" << endl;
		int age;
		cin >> age;
		tp->persionaeey[tp->numbers].age = age;

		cout << "��������ϵ�˵绰��" << endl;
		string phone;
		cin >> phone;
		tp->persionaeey[tp->numbers].phone = phone;

		cout << "��������ϵ�˵�ַ��" << endl;
		string address;
		cin >> address;
		tp->persionaeey[tp->numbers].address = address;
	}

	(tp->numbers)++;
	cout << "��ӳɹ���" << endl;
	system("pause");
	system("cls");//����
	return;

}
//��ʾ��ϵ��
void views(struct addressBooks* tp) {
	if (tp->numbers != 0) {
		for (int i = 0; i < tp->numbers; i++) {
			cout << "������" << tp->persionaeey[i].name << "\t";
			cout << "�Ա�" << tp->persionaeey[i].gender << "\t";
			cout << "���䣺" << tp->persionaeey[i].age << "\t";
			cout << "�绰��" << tp->persionaeey[i].phone << "\t";
			cout << "��ַ��" << tp->persionaeey[i].address << endl;
		}
	}
	else {
		cout << "������ϵ��" << endl;
	}
	system("pause");
	system("cls");//����
	return;

}
//ɾ����ϵ��
void deletes(struct addressBooks* tp) {
	struct addressBooks mp;
	int temp = -1;
	if (tp->numbers != 0) {
		while (true) {

			cout << "������Ҫɾ������ϵ��������" << endl;
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
				cout << "ɾ���ɹ���" << endl;
				break;
			}
			else {
				cout << "���޴���" << endl;
			}
		}
	}
	else {
		cout << "������ϵ�˿�ɾ����" << endl;
	}
	system("pause");
	system("cls");//����
	return;
}
//������ϵ��
void selectPersion(struct addressBooks* tp) {
	cout << "������Ҫ���ҵ���ϵ��������" << endl;
	int flag = -1;
	string name;
	cin >> name;
	for (int i = 0; i < tp->numbers; i++) {
		if (tp->persionaeey[i].name == name) {
			flag = 0;
			cout << "������" << tp->persionaeey[i].name << "\t";
			cout << "�Ա�" << tp->persionaeey[i].gender << "\t";
			cout << "���䣺" << tp->persionaeey[i].age << "\t";
			cout << "�绰��" << tp->persionaeey[i].phone << "\t";
			cout << "��ַ��" << tp->persionaeey[i].address << endl;
			break;
		}

	}
	if (flag == -1) {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");//����
	return;
}
//�޸���ϵ��
void update(struct addressBooks* tp) {
	cout << "������Ҫ�޸ĵ���ϵ��������" << endl;
	int flag = -1;
	string name;
	cin >> name;
	for (int i = 0; i < tp->numbers; i++) {
		if (tp->persionaeey[i].name == name) {
			flag = 0;
			cout << "��������ϵ��������" << endl;
			string name1;
			cin >> name1;
			tp->persionaeey[i].name = name1;

			cout << "��������ϵ���Ա�" << endl;
			cout << "1  ��" << endl;
			cout << "2  Ů" << endl;

			while (true) {
				int gender1;
				cin >> gender1;
				if (gender1 == 1) {
					tp->persionaeey[i].gender = "��";
					break;
				}
				else if (gender1 == 2) {
					tp->persionaeey[i].gender = "Ů";
					break;
				}
				else {
					cout << "����������������룡" << endl;
				}
			}

			cout << "��������ϵ�����䣺" << endl;
			int age;
			cin >> age;
			tp->persionaeey[i].age = age;

			cout << "��������ϵ�˵绰��" << endl;
			string phone;
			cin >> phone;
			tp->persionaeey[i].phone = phone;

			cout << "��������ϵ�˵�ַ��" << endl;
			string address;
			cin >> address;
			tp->persionaeey[i].address = address;

			cout << "�޸ĳɹ���" << endl;
			break;
		}
	}
	if (flag == -1) {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");//����
	return;
}

//�����ϵ��
void qingKong(struct addressBooks* tp) {
	tp->numbers = 0;
	cout << "�������ϵ����Ϣ��" << endl;
	system("pause");
	system("cls");//����
	return;
}
//�˳�
void exitX() {
	system("pause");
	system("cls");//����
	return;
}
//����
void defau() {
	system("exit");
	system("pause");
	system("cls");//����
	return;
}

int main(void) {

	struct addressBooks pers;
	pers.numbers = 0;
	while (true) {
		//չʾ�˵�
		showMenu();

		int select;
		cout << "��ѡ���Ӧ���ܣ�" << endl;
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
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			//system("cls");//����
			return 0;
			break;
		}
		else {
			cout << "����������������룡" << endl;
			system("pause");
			system("cls");
		}
	}
	return 0;
}