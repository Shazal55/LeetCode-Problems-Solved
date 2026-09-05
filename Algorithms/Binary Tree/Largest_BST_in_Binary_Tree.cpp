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
class Info{
public:
    int min;
    int max;
    int size;
    Info(int mi, int mx, int sz){
        min = mi;
        max = mx;
        size = sz;
    }
};
Info helper(Node* root){
    if(root == NULL){
        return Info(INT32_MAX,INT32_MIN,0);
    }
    Info left = helper(root->left);
    Info right = helper(root->right);
    
    if(root->data > left.max && root->data < right.min){
        int currMax = max(root->data,left.max);
        int currMin = min(root->data , right.min);
        int currSz = left.size + right.size + 1;
        return Info(currMin,currMax,currSz);
    }
    return Info(INT32_MIN,INT32_MAX,max(left.size,right.size));
}
int LargestBSTinBT(Node* root){ //O(n)
    Info info = helper(root);
    return info.size;
}
int main(){
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->right = new Node(7);

    cout<<LargestBSTinBT(root)<<endl;
    return 0;
}
//Output : 3
