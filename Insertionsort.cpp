#include <iostream>
using namespace std;

 

//Selection Sort
void selectionSort(int arr[], int n){
    for (int pos = 0; pos < n - 1; pos++){
        int minIdx = pos;
        for (int j = pos + 1; j < n; j++){
            if (arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        // swapping logic
        if (minIdx != pos){
            int tmp = arr[pos];
            arr[pos] = arr[minIdx];
            arr[minIdx] = tmp;
        }
    }
}

 

//Insertion Sort
void insertionSort(int a[], int n){
    for (int i = 1; i < n; i++){
        int compKey = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > compKey)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = compKey;
    }
}

 

// Helper to print the array elements
void printArray(const int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

 

int main(){
    int arr[8] = {38, 27, 43, 3, 9, 82, 10, 7};
    cout << "Before Sorting: ";
    printArray(arr, 8);
    //selectionSort(arr, 8);
    insertionSort(arr, 8);
    cout << "After Sorting: ";
    printArray(arr, 8);
    return 0;
}



