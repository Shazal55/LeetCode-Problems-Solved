#include <iostream>
using namespace std;
void bubbleSort(int arr[],int n){//O(n^2)
    for(int i=0; i<n-1; i++){
        bool isSwap = false;
        for(int j = i+1; j<n;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
                isSwap = true;
            }
        }
        if(!isSwap){
            return;
        }
    }
}

void SelectionSort(int arr[], int n){ // 0(n^2)
    for(int i = 0; i<n-1 ; i++){
        int smallest = i;
        for(int j = i+1;j<n; j++){
            if(arr[j] < arr[smallest]){
                smallest = j;
            }
        }
        swap(arr[i],arr[smallest]);
    }
}


void InsertionSort(int arr[],int n){ //O(n^2)
    for(int i = 1; i<n; i++){
        int current = arr[i];
        int prev = i-1;
        while(prev >= 0 && arr[prev]> current){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = current;
    }
}

void printArray(int *arr,int size){
    for(int i= 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int size = 4;
    int a[size] = {1,2,4,3};
    InsertionSort(a,size);
    printArray(a,size);
    return 0;
}