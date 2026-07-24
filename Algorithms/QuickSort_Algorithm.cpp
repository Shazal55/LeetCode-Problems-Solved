#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int> &arr,int st, int end){
    int idx = st-1;
    int pivot = arr[end];
    for(int j = st; j<end; j++){
        if(arr[j] <= pivot){
            idx++;
            swap(arr[j],arr[idx]);
        }
    }
    idx++;
    swap(arr[idx],arr[end]);
    return idx;
}
void QuickSort(vector<int> &arr,int st, int end){//TC : Avg/Practical -> O(nlogn), WorstCase -> O(n^2), SC: O(1)
    if(st < end){
        int pivotIdx = partition(arr,st,end);
        QuickSort(arr,st,pivotIdx-1);
        QuickSort(arr,pivotIdx+1,end);
    }
}
int main(){
    vector<int> vec = {8,3,5,2,1};
    QuickSort(vec,0,vec.size()-1);
    for(int val: vec){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
//Output : 1 2 3 5 8 