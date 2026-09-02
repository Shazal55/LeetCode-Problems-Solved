#include <iostream>
#include <vector>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
Node* insert(Node* root, int val){//O(log n)
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insert(root->left,val);
    }
    else{
        root->right = insert(root->right,val);
    }
    return root;
}
Node* BuildTree(vector<int> inorder){
    Node* root = NULL;
    for(int val : inorder){
        root = insert(root,val);
    }
    return root;
}

Node* helper(vector<int> &nums, int st, int end){
    if(st>end){
        return NULL;
    }
    int mid = st + (end-st)/2;
    Node* root = new Node(nums[mid]);
    root->left = helper(nums,st,mid-1);
    root->right = helper(nums,mid+1,end);
    return root;
}
Node* sortedArrayToBST(vector<int>& nums) {
    return helper(nums,0,nums.size()-1);
}

void inorder(Node* root,vector<int> &vec){
    if(root == NULL){
        return;
    }
    inorder(root->left,vec);
    vec.push_back(root->data);
    inorder(root->right,vec);
    return;
}
Node * merge2BST(Node* root1, Node* root2){ //O(m+n)
    vector<int> arr1;
    vector<int> arr2;
    inorder(root1,arr1);
    inorder(root2,arr2);

    vector<int> temp;
    int i = 0, j= 0;
    while(i<arr1.size() && j < arr2.size()){
        if(arr1[i] < arr2[j]){
            temp.push_back(arr1[i++]);
        }
        else{
            temp.push_back(arr2[j++]);
        }
    }
    while(i < arr1.size()){
        temp.push_back(arr1[i++]);
    }
    while(j < arr2.size()){
        temp.push_back(arr2[j++]);
    }

    return sortedArrayToBST(temp);
}
int main(){
    vector<int> arr1 = {8,2,1,10};
    vector<int> arr2 = {5,3,0};
    Node *root1 = BuildTree(arr1);
    Node *root2 = BuildTree(arr2);
    Node *root = merge2BST(root1,root2);
    vector<int> seq;
    inorder(root,seq);
    for(int val : seq){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}