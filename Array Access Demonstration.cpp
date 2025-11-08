#include<iostream>
using namespace std;
void selectionSort(int arr[],int n)
{
    for (int pos=0;pos<n-1;pos++)
    {
        int minidx=pos;

        for(int j=pos+1;j<n;j++)
        {
            if(arr[j] < arr[minidx])
            {
                minidx=j;
            }
        }

        if(minidx!=pos)
        {
            int temp=arr[pos];
            arr[pos]=arr[minidx];
            arr[minidx]=temp;
        }
    }
}

 void printArray(const int arr[],int n)
 {
    for(int k=0;k<n;k++)
    {
        cout<<arr[k]<<" ";
    }
    cout<<endl;
 }

 int main()
 {
    int arr[8]={4,6,7,2,8,10,12,1};
    cout<<"Before Sort the array"<<endl;
    printArray(arr,8);
    selectionSort(arr,8);
    cout<<"After sorting the array"<<endl;
    printArray(arr,8);
    return 0;
 }