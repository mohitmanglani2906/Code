#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
        int beg=0,end=4;
        int pos=-1;
        int arr[100];
        int val;
        int size;
        cout << "\n Enter size of an array : ";
        cin >> size;

            for(int i=0;i<size;i++){
                cout << "\n Enter an element : ";
                cin >> arr[i];
            }
            sort(arr,size+arr);
            cout << "\n Enter a value to be searched : ";
            cin>> val;
            while(beg<=end){
                    int mid=(beg+end)/2;
                    if(arr[mid]==val){
                        pos=mid;
                        cout << "\n Position of the searched value is : " << pos;
                        break;
                    }
                    else if(arr[mid]>val){
                        end=mid-1;
                    }
                    else{
                        beg=mid+1;
                    }
            }
            if(pos==-1){
                cout << "\n Value not found : ";
            }
            return 0;
}
