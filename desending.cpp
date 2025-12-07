#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n)
{
    for(int i=0;i<n-i-1;i++)
    {   
        bool isSwap=false;
        for(int j=0;j<n-1;j++)
        {
          if(arr[j]<arr[j+1])
          {
            int temp=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=temp;
            isSwap=true;
          }
        }
        if(!isSwap)
        {
            break;
        }
    }
}

void selectionSort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int highVal=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>arr[highVal])
            {
                highVal=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[highVal];
        arr[highVal]=temp;
    }
}

void insertionSort(int arr[],int n)
{
   for(int i=1;i<n;i++)
   {
    int key=arr[i];
    int j=i-1;
    while(j>=0 && arr[j]<key)
    {
    arr[j+1]=arr[j];
    j--;
    }
     arr[j+1]=key;
   }
    
}

 int binarySearch(int arr[],int n,int key)
 {
    int firstVal=0;
    int lastVal=n-1;
    while(firstVal<=lastVal)
    {
        int mid=firstVal+(lastVal-firstVal)/2;
        if(arr[mid]==key)
        {   
            cout<<"Found"<<endl;
            return mid;
        }
        else if(arr[mid]>key)
        {
            lastVal=mid-1;
        }
        else
        {
            firstVal=mid+1;
        }
    }
      return -1;
 }

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[10] = {37, 12, 89, 5, 46, 73, 21, 64, 8, 55};
    int n=10;
    int prevKey=8;
    int a[10]={10,20,30,40,50,60,70,80,90,100};
    int N=10;
    int key=70;
    selectionSort(arr,n);
    printArray(arr,n);
    int index= binarySearch(a,N,key);
    if(index==-1)
    {
        cout<<"not found"<<endl;
    }
    else
    {
        cout<<"found at index "<<index<<endl;
    }

    
   
}