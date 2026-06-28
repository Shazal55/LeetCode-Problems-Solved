#include <iostream>
#include <vector>
using namespace std;
bool isValid(vector<int> arr,int n,int m, int maxAllowed){
    int stu = 1, pages = 0;
    for(int i = 0; i<n; i++){
        if(arr[i] > maxAllowed){
            return false;
        }
        if(pages + arr[i] <= maxAllowed){
            pages += arr[i];
        }
        else{
            stu++;
            pages = arr[i];
        }
    }
    return stu > m ? false : true;
}
int allocateBook(vector<int> &arr, int n, int m){// O(nlog N)
    if(m > n){
        return -1;
    }
    int sum = 0;
    for(int val : arr){
        sum += val;
    }
    int start = 0;
    int end = sum;
    int ans = 0;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(isValid(arr,n,m,mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return ans;
}
int main(){
    vector<int> vec = {15,17,20};
    int n = 3, m = 2;
    cout<<allocateBook(vec,n,m)<<endl;
    return 0;
}
//Output : 32
//Goal : Allocate all books to m students (in order, without splitting any book) such that the maximum number of pages assigned to any single student is as small as possible