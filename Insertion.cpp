#include<iostream>
using namespace std;
int main()
{
    int initialAllocation=5;
    int a[initialAllocation]={10,20,30,40,50};
    int logicalSize=5;
    //int insertPosition=2;
    cout<<"Array Before Insertion: "<<endl;
    for(int i = 0;i<logicalSize;i++)
    {
        cout<<a[i]<<" ";
    }
    int insertPosition;
    cout<<"Please insert the index to insert element: ";
    cin>>insertPosition;
    int valueToInsert;
    cout<<"Provide the value to be inserted: ";
    cin>>valueToInsert;
    if(logicalSize >= initialAllocation)
    {
        int b[initialAllocation * 2];
        for(int i=0;i<logicalSize;i++)
        {
           b[i]=a[i];
        }
        for(int i=logicalSize - 1; i >= insertPosition; i--)
        {
           b[i+1]=b[i];
        }
        b[insertPosition]=valueToInsert; 
        logicalSize++;
        cout<<"Array After Insertion With overflow: ";
        for(int i=0;i<logicalSize;i++)
        {
            cout<<b[i]<<" ";
        }  
        cout<<endl;
    }
    else
    {
        for(int i=logicalSize - 1; i >= insertPosition; i--)
        {
           a[i+1]=a[i];
        }
        a[insertPosition]=valueToInsert; 
        logicalSize++;
        cout<<"Array After Insertion Without overflow: ";
        for(int i=0;i<logicalSize;i++)
        {
            cout<<a[i]<<" ";
        }  
        cout<<endl;

    }
   return 0;
}