#include"workerManager.h"

workerManager::workerManager() {//���캯��

    ifstream ifs(FILENAME, ios::in);//���ļ�

    //1.���ļ�������
    if (!ifs.is_open()) {
        //cout << "�ļ������ڣ�" << endl;
        this->m_EmpNum = 0;//��ʼ����¼����
        this->m_EmpArray = NULL;//��ʼ������ָ��
        this->m_FileIsEmpty = true;//��ʼ���ļ��Ƿ�Ϊ��
        ifs.close();//�ر��ļ�
        return;
    }

    //2.���ļ����ڣ�����Ϊ��
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
       // cout << "�ļ�Ϊ�գ�" << endl;
        this->m_EmpNum = 0;//��ʼ����¼����
        this->m_EmpArray = NULL;//��ʼ������ָ��
        this->m_FileIsEmpty = true;//��ʼ���ļ��Ƿ�Ϊ��
        ifs.close();//�ر��ļ�
        return;
    }

    //���ļ����ڣ��Ҽ�¼����
    int num = this->get_EmpNum();
   // cout << "ְ������Ϊ��" << num << endl;
    this->m_EmpNum = num;

    //���ٿռ�
    this->m_EmpArray = new worker * [this->m_EmpNum];

    //���ļ��е����ݴ洢������
    this->init_Emp();
}

void workerManager::show_menu() { //չʾ�˵�
    cout << "******************************************************" << endl;
    cout << "***********��ӭ����ְ������ϵͳ��************" << endl;
    cout << "***********0.�˳�����************" << endl;
    cout << "***********1.����ְ��************" << endl;
    cout << "***********2.��ʾ����ְ����Ϣ************" << endl;
    cout << "***********3.ɾ��ְ��************" << endl;
    cout << "***********4.�޸�ְ����Ϣ************" << endl;
    cout << "***********5.����ְ����Ϣ************" << endl;
    cout << "***********6.��ְ���������************" << endl;
    cout << "***********7.����ĵ�************" << endl;
    cout << "******************************************************" << endl;
}

void workerManager::exitsystem()//�˳�ϵͳ
{
    cout << "��ӭ�´�ʹ�ã�" << endl;
    system("pause");
    exit(0);
}

void workerManager::Add_Emp()//���ְ��
{
    cout << "���������ְ����������" << endl;
    int addNum;//��������
    cin >> addNum;
    if (addNum > 0) {
        int newSize=this->m_EmpNum+ addNum;//�����¿ռ�Ĵ�С
        worker **newSpace=new worker* [newSize];//�����¿ռ�

        //��ԭ���ռ��µ����ݿ������¿ռ�
        if (this->m_EmpArray != NULL) {
            for (int i = 0; i < this->m_EmpNum; i++) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        //���������
        for (int j = 0; j < addNum; j++) {

            int id;//ְ�����
            string name;//����
            int dselect;//����ѡ��

            cout << "�������" << j + 1 << "��Ա���ı��" << endl;
            cin >> id;
            cout << "�������" << j + 1 << "��Ա��������" << endl;
            cin >> name;
            cout << "��ѡ���ְ���ĸ�λ��" << endl;
            cout << "1.��ͨԱ��" << endl;
            cout << "2.����" << endl;
            cout << "3.�ϰ�" << endl;
            cin>> dselect;

            worker* work = NULL;//����ְ��ָ��
            switch (dselect) {
            case 1:
                work = new employee(id, name, 1);
                break;
            case 2:
                work = new manager(id, name, 2);
                break;
            case 3:
                work = new boss(id, name, 3);
                break;
            default:
                break;
            }
            //��������ְ��ָ�뱣�浽����
            newSpace[this->m_EmpNum + j] = work;
        }
        //�ͷ�ԭ�пռ�
        delete[] this->m_EmpArray;
        //�����¿ռ��ָ��
        this->m_EmpArray = newSpace;
        //�����µ�ְ������
        this->m_EmpNum = newSize;
        //����ְ����Ϊ�ձ�־
        this->m_FileIsEmpty = false;
        //�������ݵ��ļ�
        this->save();
        //��ʾ
        cout << "�ɹ����" << addNum << "��ְ��" << endl;
    }
    else {
        cout << "�������������" << endl;
    }
    system("pause");
    system("cls");
}

int workerManager::get_EmpNum()//ͳ���ļ��е�����
{
    ifstream ifs(FILENAME, ios::in);//���ļ�
    int id;
    string name;
    int dId;

    int num=0;//��¼����
    while (ifs >> id && ifs >> name && ifs >> dId) {
        num++;
    }
    ifs.close();
    return num;
}

void workerManager::init_Emp()//��ʼ��Ա��
{
    ifstream ifs(FILENAME, ios::in);//���ļ�

    int id;
    string name;
    int dId;

    int index=0;
    while (ifs >> id && ifs >> name && ifs >> dId) {
        worker* work = NULL;
        if (dId == 1) {
            work = new employee(id, name, dId);
        }
        else if (dId == 2) {
            work = new manager(id, name, dId);
        }
        else {
            work = new boss(id, name, dId);
        }

        this->m_EmpArray[index] = work;
        index++;
    }
    ifs.close();
}

void workerManager::show_Emp()//��ʾְ��
{
    if (this->m_FileIsEmpty) {
        cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
    }
    else {
        for (int i = 0; i < this->m_EmpNum; i++) {
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}

void workerManager::Del_Emp()//ɾ��ְ��
{
    if (this->m_FileIsEmpty) {
        cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
    }
    else {
        cout << "��������Ҫɾ����ְ����ţ�" << endl;
        int id;
        cin >> id;
        int index = this->isExist(id);
        if (index != -1) {
            for (int i = index; i < this->m_EmpNum; i++) {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--;
            this->save();
            cout << "ɾ���ɹ���" << endl;
        }
        else {
            cout << "δ�ҵ���ְ����" << endl;
        }
    }
    system("pause");
    system("cls");
}

void workerManager::Mod_Emp()//�޸�ְ��
{
    if (this->m_FileIsEmpty) {
        cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
    }
    else {
        cout << "��������Ҫ�޸ĵ�ְ����ţ�" << endl;
        int id;
        cin >> id;
        int index = this->isExist(id);
        if (index != -1) {
            delete this->m_EmpArray[index];
            int newid;
            string name;
            int dselect;
            cout << "�鵽��" << id << "��ְ������������ְ���ţ�" << endl;
            cin >> newid;
            cout << "�������µ�������" << endl;
            cin >> name;
            cout << "��ѡ���ְ���ĸ�λ��" << endl;
            cout << "1.��ͨԱ��" << endl;
            cout << "2.����" << endl;
            cout << "3.�ϰ�" << endl;
            cin >> dselect;
            worker* work = NULL;
            switch (dselect) {
            case 1:
                work = new employee(newid, name, dselect);
                break;
            case 2:
                work = new manager(newid, name, dselect);
                break;
            case 3:
                work = new boss(newid, name, dselect);
                break;
            default:
                break;
            }
            this->m_EmpArray[index] = work;
            this->save();
            cout << "�޸ĳɹ���" << endl;
        }
        else {
            cout << "δ�ҵ���ְ����" << endl;
        }
    }
    system("pause");
    system("cls");
}

void workerManager::Find_Emp()//����ְ��
{
    if (this->m_FileIsEmpty) {
        cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
    }
    else {
        cout << "��������ҷ�ʽ:" << endl;
        cout << "1.��ְ����Ų���" << endl;
        cout << "2.����������" << endl;
        int select;
        cin >> select;
        if (select == 1) {
            cout << "������Ҫ�鵽��ְ����ţ�" << endl;
            int id;
            cin >> id;
            int ref = this->isExist(id);
            if (ref != -1) {
                cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
                this->m_EmpArray[ref]->showInfo();
            }
            else {
                cout << "���޴��ˣ�" << endl;
            }
        }
        else if (select == 2) {
            cout << "��������ҵ�������" << endl;
            string name;
            bool flag=false;
            cin >> name;
            for (int i = 0; i < this->m_EmpNum; i++) {
                if (this->m_EmpArray[i]->m_Name == name) {
                    cout << "�鵽�ɹ���ְ�����Ϊ��" << this->m_EmpArray[i]->m_Id
                        << "ְ����Ϣ���£�" << endl;
                    this->m_EmpArray[i]->showInfo();
                    flag = true;
                }
            }
            if (flag == false) {
                cout << "���޴��ˣ�" << endl;
            }
        }
        else {
            cout << "�������" << endl;
        }
    }
    system("pause");
    system("cls");
}

void workerManager::sort_Emp()//��ְ������
{

    if (this->m_FileIsEmpty) {
        cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
        system("pause");
        system("cls");
    }
    else {
        cout << "��ѡ������ʽ��" << endl;
        cout << "1.��ְ������������" << endl;
        cout << "2.��ְ���Ž�������" << endl;
        int select;
        cin >> select;
        for (int i = 0; i < this->m_EmpNum; i++) {
            int minormax=i;
            for (int j = i + 1; j < this->m_EmpNum; j++) {
                if (select == 1) {//����
                    if (this->m_EmpArray[minormax]->m_Id > this->m_EmpArray[j]->m_Id) {
                        minormax = j;
                    }
                }
                else if(select == 2){//����
                    if (this->m_EmpArray[minormax]->m_Id < this->m_EmpArray[j]->m_Id) {
                        minormax = j;
                    }
                }
            }
            if (i != minormax) {
                worker* temp = this->m_EmpArray[i];
                this->m_EmpArray[i] = this->m_EmpArray[minormax];
                this->m_EmpArray[minormax] = temp;
            }
        }
        this->save();
        cout << "����ɹ��������Ľ��Ϊ��" << endl;
        this->show_Emp();
    }
    
}

void workerManager::clean_Emp()//����ļ�
{
    cout << "ȷ��Ҫ�����" << endl;
    cout << "1.ȷ��" << endl;
    cout << "2.ȡ��" << endl;
    int select;
    cin >> select;
    if (select == 1) {
        ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ������´���
        ofs.close();
        if (this->m_EmpArray != NULL) {
            for (int i = 0; i < this->m_EmpNum; i++) {
                delete this->m_EmpArray[i];
                this->m_EmpArray[i] = NULL;
            }
            delete this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_EmpNum = 0;
            this->m_FileIsEmpty = true;

        }
        cout << "��ճɹ���" << endl;
    }
    else if (select == 2) {
        system("pause");
        system("cls");
        return;
    }
    else {
        cout << "�������" << endl;
    }
    system("pause");
    system("cls");
}

int workerManager::isExist(int id)//�ж�ְ���Ƿ����
{
    int index = -1;
    for (int i = 0; i < this->m_EmpNum; i++) {
        if (this->m_EmpArray[i]->m_Id == id) {
            index = i;
            break;
        }
    }
    return index;
}

void workerManager::save()//�����ļ�
{
    ofstream ofs(FILENAME, ios::out);//����ķ�ʽ���ļ�--д�ļ�
    for (int i = 0; i < this->m_EmpNum; i++) {
        ofs << this->m_EmpArray[i]->m_Id << "  "
            << this->m_EmpArray[i]->m_Name << "  "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }
    //�ر��ļ�
    ofs.close();
}

workerManager::~workerManager() {//��������
    if (this->m_EmpArray != NULL) {
        for (int i = 0; i < this->m_EmpNum; i++) {
            delete this->m_EmpArray[i];
            this->m_EmpArray[i] = NULL;
        }
        delete this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}
