#include<iostream>
using namespace std;
int main()
{
    int InitialAllocation=5;
    int a[InitialAllocation]={10,20,30,40,50};
        int logicalSize=5;
    cout<<"Array Before Deletation: "<<endl;
    for(int i = 0;i<logicalSize;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int valueToDelete;
    int deletePosition;
    cout<<"Array index want To Delete"<<endl;
    cin>>deletePosition;
    for(int i=deletePosition ; i < logicalSize-1; i++)
        {
           a[i]=a[i+1];
        } 
        logicalSize--;
        cout<<"Array After Deletation: ";
        for(int i=0;i<logicalSize;i++)
        {
            cout<<a[i]<<" ";
        }  
        cout<<endl;
}