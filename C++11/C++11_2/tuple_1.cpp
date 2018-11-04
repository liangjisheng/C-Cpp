#include <iostream>
#include <tuple>
#include <string>

using namespace std;

std::tuple<double, char, std::string> get_student(int id)
{
    // 返回类型被推断为std::tuple<double, char, std::string>
    if (0 == id)
        return std::make_tuple(3.8, 'A', "张三");
    if (1 == id)
        return std::make_tuple(2.9, 'C', "李四");
    if (2 == id)
        return std::make_tuple(1.7, 'D', "王五");

    // 只写0会编译失败
    return std::make_tuple(0, 'D', "null");
}


int main()
{
    auto student = get_student(0);
    cout << "ID:0, " << "GPA: " << std::get<0>(student) << ","
         << "成绩: " << std::get<1>(student) << ","
         << "姓名: " << std::get<2>(student) << endl;

    double gpa;
    char grade;
    string name;

    // 元组进行拆包
    std::tie(gpa, grade, name) = get_student(1);
    cout << "ID: 1, " << "GPA: " << gpa << ", "
         << "成绩: " << grade << ", 姓名: " << name << endl;

    return 0;
}
