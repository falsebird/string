#include <iostream>
#include <cstring>
#include "myString.h"
#pragma warning(disable:4996)
using namespace std;
// ���캯��
String::String(const char* str)
{
    if (str == nullptr)  //  ��m_data��NULL �ж�
    {
        m_data = new char[1];   //  �Կ��ַ����Զ������Ž�����־'\0'��
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

// �������캯��
String::String(const String& str)   //  �������Ϊconst��
{
    m_size = str.m_size;
    m_data = new char[m_size + 1];  // ��m_data��NULL �ж�
    strcpy(m_data, str.m_data);
}

// ��������
String::~String()
{
    delete[] m_data;
}

// �ַ�����ֵ����
String& String::operator=(const String& str)  // �������Ϊconst
{
    if (this == &str)    //����Ը�ֵ
        return *this;

    delete[] m_data;    //�ͷ�ԭ�е��ڴ���Դ
    m_size = strlen(str.m_data);
    m_data = new char[m_size + 1];  // ��m_data��NULL �ж�
    strcpy(m_data, str.m_data);
    return *this;       // ���ر����������
}



String& operator+(const String& str1, const String& str2)
{
    // TODO: �ڴ˴����� return ���
    String temp;
    temp.m_size = str1.get_size() + str2.get_size();
    temp.m_data = new char[temp.m_size + 1];
    strcpy(temp.m_data, str1.m_data);
    strcat(temp.m_data, str2.m_data);
    return temp;
}

// ��������дopreater����
ostream& operator << (ostream& os, const String& str) {
    return os << str.get_str();
}