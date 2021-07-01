#include <iostream>
#include <cstring>
#include "myString.h"
#pragma warning(disable:4996)
using namespace std;
// 构造函数
String::String(const char* str)
{
    if (str == nullptr)  //  对m_data加NULL 判断
    {
        m_data = new char[1];   //  对空字符串自动申请存放结束标志'\0'的
        m_data[0] = '\0';
        m_size = 0;
    }
    else
    {
        m_size = strlen(str);
        m_data = new char[m_size + 1];
        strcpy(m_data, str);
    }
}

// 拷贝构造函数
String::String(const String& str)   //  输入参数为const型
{
    m_size = str.m_size;
    m_data = new char[m_size + 1];  // 对m_data加NULL 判断
    strcpy(m_data, str.m_data);
}

// 析构函数
String::~String()
{
    delete[] m_data;
}

// 字符串赋值函数
String& String::operator=(const String& str)  // 输入参数为const
{
    if (this == &str)    //检查自赋值
        return *this;

    delete[] m_data;    //释放原有的内存资源
    m_size = strlen(str.m_data);
    m_data = new char[m_size + 1];  // 对m_data加NULL 判断
    strcpy(m_data, str.m_data);
    return *this;       // 返回本对象的引用
}



String& operator+(const String& str1, const String& str2)
{
    // TODO: 在此处插入 return 语句
    String temp;
    temp.m_size = str1.get_size() + str2.get_size();
    temp.m_data = new char[temp.m_size + 1];
    strcpy(temp.m_data, str1.m_data);
    strcat(temp.m_data, str2.m_data);
    return temp;
}

// 在类外重写opreater函数
ostream& operator << (ostream& os, const String& str) {
    return os << str.get_str();
}