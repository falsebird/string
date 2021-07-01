#include<iostream>
#include "myString.h"
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

int main() {
    test_copy();
    return 0;
}