#include<iostream>
using namespace std;

void findTargetSum(int numbers[],int n,int t,int &c1,int &c2)
{   
    int i=0;
    int j=n-1;
    while(i<=j)
    {   
        if(numbers[i]+numbers[j]==t)
        {
            c1=i;
            c2=j;
            return;
        }
        if(numbers[i]+numbers[j]<t)
        {
            i++;
        } 
        else if(numbers[i]+numbers[j]>t)
        {
            j--;
        }
    }
    c1=-1;
    c2=-1;
    
}

int main()
{
    int numbers[]={2,7,11,15};
    int n=4;
    int c1,c2;
    findTargetSum(numbers,4,9,c1,c2);
       cout <<"["<<c1<<","<<c2 <<"]";
       return 0;
}