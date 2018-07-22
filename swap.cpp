#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int a=5,b=4;
    a=a^b;
    b=a^b;
    a=a^b;
    cout << a << "\t" << b ;
    cout << endl;
    b=a+b-(a=b);
    cout << a << "\t" << b ;


    return 0;








}
