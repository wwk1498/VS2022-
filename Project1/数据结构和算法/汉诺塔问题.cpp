#include<iostream>
using namespace std;

//汉诺塔问题  时间复杂度O(2的n次方)
void hanoi(int n, char start, char middle, char end)//n--圆盘个数，start--源，middle--借，end--目
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