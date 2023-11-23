#include<iostream>
#include<algorithm>//算法头文件
#include <vector>
#include <list>
/*
find(begin, end, value): 在指定的范围内查找value的第一个出现位置，并返回迭代器。如果未找到，则返回end()。

sort(begin, end): 对指定范围内的元素进行升序排序。

reverse(begin, end): 反转指定范围内的元素的顺序。

***back_inserter(vec); 把某个范围内的元素插入到vec容器的尾部,函数本身不会直接改变容器的大小，但它允许通过插入元素来间接改变容器的大小。//可以不使用头文件

***front_inserter(vec); 把某个范围内的元素插入到vec容器的头部,函数本身不会直接改变容器的大小，但它允许通过插入元素来间接改变容器的大小。//可以不使用头文件

max(a, b): 返回a和b中的较大值。

min(a, b): 返回a和b中的较小值。

count(begin, end, value): 统计指定范围内等于value的元素个数。

accumulate(begin, end, init): 对指定范围内的元素进行累加，初始值为init。

copy(begin, end, dest): 复制指定范围内的元素到目标位置。

remove(begin, end, value): 删除指定范围内等于value的所有元素，返回删除后的范围的末尾迭代器。

binary_search(begin, end, value): 在已排序的指定范围内查找value，返回是否找到的布尔值。

unique(begin, end): 移除指定范围内相邻重复的元素，返回新的范围的末尾迭代器。

next_permutation(begin, end): 获取指定范围内的下一个排列，并返回是否成功的布尔值。

transform(begin1, end1, begin2, dest, function): 对指定范围内的元素应用指定的函数，并将结果存储到目标位置
*/



// 自定义的一元操作函数，将参数加倍并返回
int doubleValue(int x) {
    return 2 * x;
}

//自定义函数，递减
bool fc(int x, int y) {
    return x > y;
}


using namespace std;

int main() {

    //1.find()用法，在容器中查找指定值，返回迭代器指向第一个匹配的元素。
    vector<int> vec{ 1, 2, 3, 4, 5 };

    auto it = find(vec.begin(), vec.end(), 3);

    if (it != vec.end()) {
        // 找到了元素
        cout << "找到了元素：" << *it << endl;
    }
    else {
        // 未找到元素
        cout << "未找到元素" << endl;
    }



    //2.sort()用法，对容器中的元素进行排序，可以使用自定义的比较函数或操作符。
    vector<int> vec{ 3, 1, 4, 1, 5 };

    sort(vec.begin(), vec.end());  // 默认升序排序

    // 自定义降序排序
    sort(vec.begin(), vec.end(), fc);

    // 输出排序结果
    for (const auto& element : vec) {
       cout << element << " ";
    }




    //3. count()：计算指定值在容器中出现的次数。
    vector<int> vec{ 1, 2, 2, 3, 2, 4, 5, 2 };

    int count1 = count(vec.begin(), vec.end(), 2);

    cout << "元素 2 在容器中出现的次数：" << count1 << endl;




    //4. remove()：用于从容器中移除指定的元素。它并不是真正地删除元素，而是将符合条件的元素移动到容器的末尾，
    // 并返回指向新的逻辑终点的迭代器。{1,2,3,4,3,5}--->{1,2,4,5,3,3}
   
    vector<int> vec{ 1, 2, 3, 2, 4, 2, 5 };

    // 移除所有值为2的元素
    auto it = remove(vec.begin(), vec.end(), 2);

    // 调整容器大小，使其仅包含不重复元素
    vec.erase(it, vec.end());//erase()是容器成员函数

    // 输出结果
    for (const auto& element : vec) {
        cout << element << " ";
    }
    

    //5.copy()：将一个容器中的元素复制到另一个容器。
    vector<int> src{ 1, 2, 3, 4, 5 };
    list<int> dest;

    // 将 src 容器中的元素复制到 dest 容器
    copy(src.begin(), src.end(),back_inserter(dest));

    // 输出结果
    for (const auto & element : dest) {
        cout << element << " ";
    }

    //6.transform()函数是<algorithm>库中的一个常用函数，用于对指定范围内的元素应用指定的函数，
    // 并将结果存储到目标位置。函数签名如下：
    
    //template<class InputIt, class OutputIt, class UnaryOperation>
    //OutputIt transform(InputIt first1, InputIt last1, OutputIt d_first, UnaryOperation unary_op);
    /*
    * first1和last1：定义源范围的迭代器，表示进行转换的元素范围。
    d_first：定义目标范围的迭代器，表示结果存储的位置。
    unary_op：一元操作函数（函数对象或函数指针），表示对源范围内的每个元素进行的操作。
    */

    vector<int> numbers = { 1, 2, 3, 4, 5 };
    vector<int> doubledNumbers(numbers.size());//创建doubledNumbers容器，并且大小为numbers.size()，且初始化元素为默认值（0）
    // list<int> doubledNumbers;//创建doubledNumbers容器,是空容器
     
    // 将numbers中的每个元素加倍后存储到doubledNumbers中、、doubledNumbers.begin()
    transform(numbers.begin(), numbers.end(), back_inserter(doubledNumbers), doubleValue);

    // 输出doubledNumbers中的元素
    for (int num : doubledNumbers) {
        cout << num << " ";
    }













	system("pause");
	return 0;
}