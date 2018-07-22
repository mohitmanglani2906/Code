#include<iostream>
#include<stdio.h>
using namespace std;
class Insertion_sort{
public:
        int arr[1000],size;
        Insertion_sort(){
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
                for(int i=1;i<size;i++){
                    int temp=arr[i];
                int j=i-1;
                    while(j>=0&&arr[j]>temp){
                        arr[j+1]=arr[j];
                        j=j-1;
                    }
                    arr[j+1]=temp;
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
    Insertion_sort s1;
    s1.sorting(); cout << "\n After sorting : ";
    s1.showarray();
    return 0;
}



