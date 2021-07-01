#pragma once
#include <iostream>
#include <cstring>
using namespace std;
class String {
public:
    // Ĭ�Ϲ��캯��
    String(const char* str = nullptr);
    // �������캯��
    String(const String& str);
    // ��������
    ~String();
    // �ַ�����ֵ����
    
    char* get_str() const { return m_data; };//inline
    int get_size() const { return m_size; };//
    String& operator=(const String& str);
    //friend String& operator + (const String& str1, const String& str2);
    friend ostream& operator << (ostream& os, const String &str);//��Ԫ����

private:
    char* m_data;
    int m_size;
};

