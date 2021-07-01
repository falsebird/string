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
    a.push_back(1);//—È÷§push_back
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

int main() {
    test_cout();
    return 0;
}