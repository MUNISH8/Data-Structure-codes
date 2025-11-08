#include<iostream>
using namespace std;
int check;
void printArray(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        check=0;
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
                check++;
            }

        }
        if(check==0)
        {
            break;
        }
    }
}
int main()
{   
    int a[]={20,10,12,2,1};
    int n=5;
    cout<<"Array before Bubble Sorting"<<endl;
    printArray(a,5);
    cout<<"Array After Bubble sort"<<endl;
    bubbleSort(a,5);
    printArray(a,5);
}