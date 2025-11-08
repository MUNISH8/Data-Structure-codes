#include<iostream>
using namespace std;
void printArray(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void linearSearch(int a[],int n,int find)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==find)
        {
            cout<<"Element found at "<<i<<" number index"<<endl;
        }
    }
}

int main()
{
    int a[]={20,10,12,2,1};
    int n=5;
    cout<<"The Array"<<endl;
    printArray(a,5);
    cout<<"Doing linear Search in the given Array"<<endl;
    linearSearch(a,5,12);    
}