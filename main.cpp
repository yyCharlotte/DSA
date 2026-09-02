//
// Created by y2295 on 2026/9/2.
//
#include <iostream>
#include <windows.h>
using namespace std;

class Person
{
public:
    // 无参构造
    Person()
    {
        cout << "无参构造" << endl;
    }
    // 有参构造
    Person(int a)
    {
        age = a;
        cout << "有参构造 int" << endl;
    }
    Person(string name, int a)
    {
        this->name = name;
        age = a;
        cout << "双参数构造" << endl;
    }

private:
    string name;
    int age;
};

int main()
{
    SetConsoleOutputCP(65001);
    Person p1;             // 无参构造
    Person p2(18);         // 有参构造
    Person p3("LiHua", 20);
    // C++11列表初始化写法
    Person p4{16};
    cout<<"你好"<<endl;
    return 0;

}