#include<iostream>
using namespace std;

void selectionsort(int arr[], int n)
{
    for(int pos = 0; pos < n - 1; pos++)
    {
        int minidx = pos;
        for(int j = pos + 1; j < n; j++)
        {
            if(arr[j] < arr[minidx])
            {
                minidx = j;
            }
        }
        // Swap after finding the minimum in the rest of the array
        if(minidx != pos)
        {
            int tmp = arr[pos];
            arr[pos] = arr[minidx];
            arr[minidx] = tmp;
        }
    }
}
//Helper to print the array element
void printArray (const int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
  int arr[8]={38,27,43,3,9,82,10,7};
  cout<<"Before Sorting"<<endl;
  printArray(arr,8);
  selectionsort(arr,8);
  cout<<"After sorting"<<endl;
  printArray(arr,8);
  return 0;
}