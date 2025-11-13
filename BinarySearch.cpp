#include <iostream>
using namespace std;
 
int binarySearch(int arr[], int n, int key){
    int firstIdx = 0;
    int lastIdx = n - 1;
 
    while(firstIdx <= lastIdx){
        int mid = firstIdx + (lastIdx - firstIdx) / 2; // middle index
 
        if (arr[mid] == key){
            return mid; // key found at mid index
        }
        else if (arr[mid] < key){
            firstIdx = mid + 1; // search right half
        }
        else {
            lastIdx = mid - 1; // search left half
        }
    }
 
    return -1; // not found
}
 
int main(){
    // Array must be sorted
    int arr[7] = {4, 10, 23, 45, 67, 77, 83};
    int index = binarySearch(arr, 7, 77);
    if (index == -1){
        cout << "Key not found." << endl;
    }
    else{
        cout << "Key found at index: " << index << endl;
    }
    return 0;
}