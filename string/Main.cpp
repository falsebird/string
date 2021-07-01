#include<iostream>
#include<iterator>
#include "myString.h"
#include "String_T.h"
using namespace std;



int testgouzao() {
    String st = "hello";
    std::cout << st;
    return 0;
}
int test_copy() {
    String s1 = "hello";
    String s2 = "word";
    try {
        String s3 =  s2 + s1 ;
        cout << s3 << endl;
        return 0;
    }
    catch (...) {
        cout << "catch (...)" << endl;
        return -1;
    }
   
}

void test_cout()
{
    String_T<int> a(5);
    a.push_back(1);//验证push_back
    a.push_back(2);
    a.push_back(3);
    cout << a << endl;
    int *ita = a.begin();

    cout << *ita << endl;
    cout << *++ita << endl;
    int *endit = a.end();
    ita = ++ita;
    if (ita == endit) {
        cout << "end is here" << endl;
    }
    
}
void test_erase() {
    String_T<int> a(5);
    a.push_back(1);//验证push_back
    a.push_back(2);
    a.push_back(3);
    cout << a << endl;
    int* ita = a.begin();
    ++ita;
    //ita = a.erase(ita);# 正常是返回被删值位置的指针
    //cout << *ita << endl;
    //cout << a << endl;
    //test out out index
    ++ita;
    //++ita;
    //++ita;
    //++ita;
    ita = a.erase(ita);//当超出范围是返沪最后一个元素的市镇
    cout << *ita << endl;
    cout << a << endl;


}   

int test_initwithval() {
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    String_T<int> st(10);
    cout << st << endl;
    return 0;
}
int main() {
    test_erase();
    return 0;
}