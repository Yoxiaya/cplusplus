#include <iostream>
#include <string>

int sum(int a, int b)
{
    return a + b;
}
struct student
{
    int id;
    int age;
    char sex[4];
    char name[10];
    float score;
    student() : id(), age(), sex(), name("张三"), score(80.0) {}
};
int main()
{
    int a = 10;
    float b = 20.0;
    bool c = false;
    char d = 'a';
    wchar_t e = L'a';
    double f = 123.456;

    int arr[5];
    int* g = &arr[0];
    int* h = &arr[1];

    int i = a;
    a = 20;
    int &j = a;
    student stu;
    std::string str = "hello,Alice";
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;
    std::cout << "f = " << f << std::endl;
    std::cout << "arr = " << arr << std::endl;
    std::cout << "g = " << g << std::endl;
    std::cout << "h = " << h << std::endl;
    std::cout << "i = " << a << '-' << i << std::endl;
    std::cout << "j = " << a << '-' << j << std::endl;
    std::cout << "stu = " << stu.id << '-' << stu.age << '-' << stu.sex << '-' << stu.name << '-' << stu.score << std::endl;
    std::cout << "str = " << str << std::endl;
    size_t len = str.length();
    size_t position = str.find("Alice");
    std::cout << "len = " << len << std::endl;
    std::cout << "position = " << position << std::endl;

    return 0;
}