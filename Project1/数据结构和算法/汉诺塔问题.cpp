#include<iostream>
using namespace std;

//��ŵ������  ʱ�临�Ӷ�O(2��n�η�)
void hanoi(int n, char start, char middle, char end)//n--Բ�̸�����start--Դ��middle--�裬end--Ŀ
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", start, end);
        return;
    }

    hanoi(n - 1, start, end, middle);
    printf("Move disk %d from %c to %c\n", n, start, end);
    hanoi(n - 1, middle, start, end);
}

int main() {

    int n;
    printf("Enter the number of disks: ");
    cin >> n;

    printf("Steps to solve the Hanoi Tower problem:\n");
    hanoi(n, 'A', 'B', 'C');

	system("pause");
	return 0;
}