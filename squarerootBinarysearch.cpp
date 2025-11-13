#include<iostream>
using namespace std;

int binaryrootSquare(int num)
{
    int firstRange=0;
    int lastRange=num;
    while(firstRange<=lastRange)
    {
        int midRange=firstRange+(lastRange-firstRange)/2;
        if(midRange*midRange==num)
        {
            return midRange;
        }
        else if(midRange*midRange<num)
        {
            firstRange=midRange+1;
        }
        else
        {
            lastRange=midRange-1;
        }
    }
    return -1;
}

int main()
{
    int num=9;
    int result=binaryrootSquare(9);
    if (result==-1)
    {
        cout<<"Square root not found"<<endl;
    }
    else
    {
        cout<<"Square root found "<<result<<endl;
    }
}