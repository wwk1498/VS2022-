#include<iostream>
#include<algorithm>//�㷨ͷ�ļ�
#include <vector>
#include <list>
/*
find(begin, end, value): ��ָ���ķ�Χ�ڲ���value�ĵ�һ������λ�ã������ص����������δ�ҵ����򷵻�end()��

sort(begin, end): ��ָ����Χ�ڵ�Ԫ�ؽ�����������

reverse(begin, end): ��תָ����Χ�ڵ�Ԫ�ص�˳��

***back_inserter(vec); ��ĳ����Χ�ڵ�Ԫ�ز��뵽vec������β��,����������ֱ�Ӹı������Ĵ�С����������ͨ������Ԫ������Ӹı������Ĵ�С��//���Բ�ʹ��ͷ�ļ�

***front_inserter(vec); ��ĳ����Χ�ڵ�Ԫ�ز��뵽vec������ͷ��,����������ֱ�Ӹı������Ĵ�С����������ͨ������Ԫ������Ӹı������Ĵ�С��//���Բ�ʹ��ͷ�ļ�

max(a, b): ����a��b�еĽϴ�ֵ��

min(a, b): ����a��b�еĽ�Сֵ��

count(begin, end, value): ͳ��ָ����Χ�ڵ���value��Ԫ�ظ�����

accumulate(begin, end, init): ��ָ����Χ�ڵ�Ԫ�ؽ����ۼӣ���ʼֵΪinit��

copy(begin, end, dest): ����ָ����Χ�ڵ�Ԫ�ص�Ŀ��λ�á�

remove(begin, end, value): ɾ��ָ����Χ�ڵ���value������Ԫ�أ�����ɾ����ķ�Χ��ĩβ��������

binary_search(begin, end, value): ���������ָ����Χ�ڲ���value�������Ƿ��ҵ��Ĳ���ֵ��

unique(begin, end): �Ƴ�ָ����Χ�������ظ���Ԫ�أ������µķ�Χ��ĩβ��������

next_permutation(begin, end): ��ȡָ����Χ�ڵ���һ�����У��������Ƿ�ɹ��Ĳ���ֵ��

transform(begin1, end1, begin2, dest, function): ��ָ����Χ�ڵ�Ԫ��Ӧ��ָ���ĺ�������������洢��Ŀ��λ��
*/



// �Զ����һԪ�����������������ӱ�������
int doubleValue(int x) {
    return 2 * x;
}

//�Զ��庯�����ݼ�
bool fc(int x, int y) {
    return x > y;
}


using namespace std;

int main() {

    //1.find()�÷����������в���ָ��ֵ�����ص�����ָ���һ��ƥ���Ԫ�ء�
    vector<int> vec{ 1, 2, 3, 4, 5 };

    auto it = find(vec.begin(), vec.end(), 3);

    if (it != vec.end()) {
        // �ҵ���Ԫ��
        cout << "�ҵ���Ԫ�أ�" << *it << endl;
    }
    else {
        // δ�ҵ�Ԫ��
        cout << "δ�ҵ�Ԫ��" << endl;
    }



    //2.sort()�÷����������е�Ԫ�ؽ������򣬿���ʹ���Զ���ıȽϺ������������
    vector<int> vec{ 3, 1, 4, 1, 5 };

    sort(vec.begin(), vec.end());  // Ĭ����������

    // �Զ��彵������
    sort(vec.begin(), vec.end(), fc);

    // ���������
    for (const auto& element : vec) {
       cout << element << " ";
    }




    //3. count()������ָ��ֵ�������г��ֵĴ�����
    vector<int> vec{ 1, 2, 2, 3, 2, 4, 5, 2 };

    int count1 = count(vec.begin(), vec.end(), 2);

    cout << "Ԫ�� 2 �������г��ֵĴ�����" << count1 << endl;




    //4. remove()�����ڴ��������Ƴ�ָ����Ԫ�ء���������������ɾ��Ԫ�أ����ǽ�����������Ԫ���ƶ���������ĩβ��
    // ������ָ���µ��߼��յ�ĵ�������{1,2,3,4,3,5}--->{1,2,4,5,3,3}
   
    vector<int> vec{ 1, 2, 3, 2, 4, 2, 5 };

    // �Ƴ�����ֵΪ2��Ԫ��
    auto it = remove(vec.begin(), vec.end(), 2);

    // ����������С��ʹ����������ظ�Ԫ��
    vec.erase(it, vec.end());//erase()��������Ա����

    // ������
    for (const auto& element : vec) {
        cout << element << " ";
    }
    

    //5.copy()����һ�������е�Ԫ�ظ��Ƶ���һ��������
    vector<int> src{ 1, 2, 3, 4, 5 };
    list<int> dest;

    // �� src �����е�Ԫ�ظ��Ƶ� dest ����
    copy(src.begin(), src.end(),back_inserter(dest));

    // ������
    for (const auto & element : dest) {
        cout << element << " ";
    }

    //6.transform()������<algorithm>���е�һ�����ú��������ڶ�ָ����Χ�ڵ�Ԫ��Ӧ��ָ���ĺ�����
    // ��������洢��Ŀ��λ�á�����ǩ�����£�
    
    //template<class InputIt, class OutputIt, class UnaryOperation>
    //OutputIt transform(InputIt first1, InputIt last1, OutputIt d_first, UnaryOperation unary_op);
    /*
    * first1��last1������Դ��Χ�ĵ���������ʾ����ת����Ԫ�ط�Χ��
    d_first������Ŀ�귶Χ�ĵ���������ʾ����洢��λ�á�
    unary_op��һԪ���������������������ָ�룩����ʾ��Դ��Χ�ڵ�ÿ��Ԫ�ؽ��еĲ�����
    */

    vector<int> numbers = { 1, 2, 3, 4, 5 };
    vector<int> doubledNumbers(numbers.size());//����doubledNumbers���������Ҵ�СΪnumbers.size()���ҳ�ʼ��Ԫ��ΪĬ��ֵ��0��
    // list<int> doubledNumbers;//����doubledNumbers����,�ǿ�����
     
    // ��numbers�е�ÿ��Ԫ�ؼӱ���洢��doubledNumbers�С���doubledNumbers.begin()
    transform(numbers.begin(), numbers.end(), back_inserter(doubledNumbers), doubleValue);

    // ���doubledNumbers�е�Ԫ��
    for (int num : doubledNumbers) {
        cout << num << " ";
    }













	system("pause");
	return 0;
}