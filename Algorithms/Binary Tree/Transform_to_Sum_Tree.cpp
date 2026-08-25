#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};
//Creating a Tree
static int idx = -1;
Node *buildTree(vector<int> preorder){//TC : O(n)
    idx++;
    if(preorder[idx] == -1){
        return NULL;
    }
    Node *root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}
// Pre-Order Traversal
//Root - left - Right
void preOrderPrint(Node *root){//TC : O(n)
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}
int SumTree(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftSum = SumTree(root->left);
    int rightSum = SumTree(root->right);
    root->data += leftSum + rightSum;
    return root->data;
}
int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node *root = buildTree(preorder);
    cout<<"PreOrder before Transformation : ";
    preOrderPrint(root);
    cout<<endl;
    cout<<"Sum of Tree : "<<SumTree(root)<<endl;
    cout<<"PreOrder after Transformation : ";
    preOrderPrint(root);

    return 0; 
}
/*
Output : 
PreOrder before Transformation : 1 2 3 4 5 
Sum of Tree : 15
PreOrder after Transformation : 15 2 12 4 5 
*/