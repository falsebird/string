#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class String {
public:
    // 默认构造函数
    String(const char* str = nullptr);
    // 拷贝构造函数
    String(const String& str);
    // 析构函数
    ~String();
    // 字符串赋值函数
    
    char* get_str() const { return m_data; };//inline
    int get_size() const { return m_size; };//
    String& operator=(const String& str);
    //friend String& operator + (const String& str1, const String& str2);
    friend ostream& operator << (ostream& os, const String &str);//友元函数

private:
    char* m_data;
    int m_size;
};

