#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//Prefix Array Approach
int trap(vector<int>& height) {//TC : O(n) , SC : O(n)
    int n = height.size();
    int ans = 0;
    vector<int> Lmax(n,0);
    vector<int> Rmax(n,0);
    Lmax[0] = height[0];
    Rmax[n-1] = height[n-1];
    for(int i = 1; i<n; i++){
        Lmax[i] = max(Lmax[i-1],height[i]);
    }
    for(int i = n-2; i>=0; i--){
        Rmax[i] = max(Rmax[i+1],height[i]);
    }
    for(int i =0 ; i<n; i++){
        ans +=min(Lmax[i],Rmax[i]) - height[i];
    }
    return ans;
}
//Two Pointer Approach
int trap1(vector<int>& height) {
    int ans = 0;
    int n = height.size();
    int Lmax = 0;
    int Rmax = 0;
    int l = 0; 
    int r = n-1;
    while(l<r){
        Lmax = max(Lmax,height[l]);
        Rmax = max(Rmax,height[r]);
        if(Lmax < Rmax){
            ans += Lmax - height[l];
            l++;
        }
        else{
            ans += Rmax - height[r];
            r--;
        }
    }
    return ans;
}
int main(){
    vector<int> vec = {4,2,0,3,2,5};
    cout<<trap1(vec)<<endl;
    return 0;
}