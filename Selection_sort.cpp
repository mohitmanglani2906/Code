#include<iostream>
#include<stdio.h>
using namespace std;
class Selection_sort{
public:
        int arr[1000],size;
        Selection_sort(){
                    cout << "\n Enter size of an array : ";
                    cin>>size;
                        for(int i=0;i<size;i++){
                            cout << "Enter an element : ";
                            cin >> arr[i];
                        }
                    cout << "\n Before sorting  :";
                        for(int i=0;i<size;i++)
                        {
                            cout << endl << arr[i];
                        }
        }
        void sorting(){
        int min;
            for(int i=0;i<size-1;i++){
                min=i;
                for(int j=i+1;j<size;j++){
                    if(arr[j]<arr[min]){
                        min=j;
                    }
                }
                    int temp=arr[i];
                    arr[i]=arr[min];
                    arr[min]=temp;

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
    Selection_sort s1;
    s1.sorting(); cout << "\n After sorting : ";
    s1.showarray();
    return 0;
}


