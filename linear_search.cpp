#include<iostream>
#include<conio.h>
using namespace std;
int main(){

int arr[100];
int val,pos=0;
int size;
        cout << "\n Enter size of an array : ";
        cin >> size;
                for(int i=0;i<size;i++){
                        cout << "\n Enter an element : ";
                        cin >> arr[i];
                }
        cout << "\n Enter value to be searched : ";
        cin>> val;
                for(int i=0;i<size;i++){
                    if(arr[i]==val){
                        pos=i;
                        break;
                    }
                }
                if(pos!=0){
                cout << "\n Value found : ";
                cout << "\n Position of the searched value is : " << pos+1;
                }
                else{
                    cout << "\n Value not found : ";
                }
                    getch();
                    return 0;
}
