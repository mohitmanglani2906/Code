#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    int a=5,b=4;
    a=a^b; // 1st method
    b=a^b;
    a=a^b;
    cout << a << "\t" << b ;
    cout << endl;
    b=a+b-(a=b); // 2nd method
    cout << a << "\t" << b ;

    a=a+b;   // 3rd method
    b=a-b;
    a=a-b;
        cout << endl;
        cout << a << "\t" << b;


    return 0;








}
