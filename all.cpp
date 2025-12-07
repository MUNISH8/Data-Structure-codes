#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        bool isSwap=false;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                isSwap=true;
            }
        }
        if(!isSwap)
        {
            break;
        }
    }

}

void slectionSort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int lowestVal=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[lowestVal])
            {
                lowestVal=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[lowestVal];
        arr[lowestVal]=temp;
    }
}

void insertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int prevKey=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>prevKey)
        {
          arr[j+1]=arr[j];
          j-- ;   
        }
        arr[j+1]=prevKey;
    }
}

int  binarySearch(int arr[],int n,int key)
{
  int firstVal=0;
  int lastVal=n-1;
  while(firstVal<=lastVal)
  {
    int midVal=firstVal+(lastVal-firstVal)/2;
    if(arr[midVal]==key)
    {
        return midVal;
    }
    else if(arr[midVal]>key)
    {
        lastVal=midVal-1;
    }
    else
    {
        firstVal=midVal+1;
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
bubbleSort(arr,n);
printArray(arr,n);
binarySearch(arr,n,5);

}