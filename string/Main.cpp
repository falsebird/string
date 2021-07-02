#include<iostream>
#include<iterator>
#include "myString.h"
#include "String_T.h"
using namespace std;



int testgouzao() {
    int a[] = { 1,2,3,4,5 };
  
    String_T<int> st(a,5);
    std::cout << st<<endl;
    return 0;
}
int test_copy() {
    int a[] = { 1,2,3,4,5 };

    String_T<int> st(a, 5);
    try {
        String_T<int> s3 =  st;
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
    ita = a.erase(ita);//当超出范围是返回最后一个元素的后边的指针
    cout << *ita << endl;
    cout << a << endl;


}   

int test_insert() {
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    String_T<int> st(a,10);
    cout << st << endl;
    st.insert(st.begin(), 1000);
    cout << st << endl;
    st.insert(st.end(), 1000);
    cout << st << endl;
    st.insert(st.end(), 1000);
    cout << st << endl;
    String_T<int>::iterator ptr = st.begin();
    ptr++;
    ptr++;
    ptr++;
    ptr++;
    st.insert(ptr, 1000);
    cout << st << endl;
    return 0;
}

int test_popout() {
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    String_T<int> st(a, 10);
    cout << st << endl;
    st.pop_back();
    cout << st << endl;
    st.pop_back();
    cout << st << endl;
    st.pop_back();
    cout << st << endl;
    st.pop_back();
    return 0;
}


int main() {
    test_popout();
    return 0;
}