#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
int size;
/*void sort_array(int arr[],int size);
void sort_array(int arr[],int size){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(arr[j]>arr[j+1]){
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
}*/
class Bubble_sort{
public:
    int arr[10000],size;
    Bubble_sort(){
        cout << "\n Enter size of an array : ";
        cin>>size;
            for(int i=0;i<size;i++){
                cout << "Enter an element : ";
                cin >> arr[i];
            }
            cout << "\n Before sorting  :";
            for(int i=0;i<size;i++){
                cout << endl << arr[i];
            }
    }
    void sorting(){
        for(int i=0;i<size-1;i++)
            {
                for(int j=0;j<size-1-i;j++)
                 {
                    if(arr[j]>arr[j+1])
                        {
                                int temp=arr[j];
                                arr[j]=arr[j+1];
                                arr[j+1]=temp;
                        }
                 }
            }
    }
    void showarray()
    {
        for(int i=0;i<size;i++)
            {
                cout << endl << arr[i];

            }

    }
};


int main(){
    Bubble_sort b1;
    b1.sorting(); cout << "\n After sorting : ";
    b1.showarray();
    return 0;
}
