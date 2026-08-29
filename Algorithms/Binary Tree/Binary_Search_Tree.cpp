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


void InOrder(Node* root){
    if(root == NULL){
        return;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}

bool Search(Node *root,int k){ //O(logn)
    if(root == NULL){
        return false;
    }
    if(root->data == k){
        return true;
    }
    if(k < root->data){
        return Search(root->left,k);
    }
    else{
        return Search(root->right,k);
    }
    return false;

}
Node* getInorderSuccessor(Node* root){ // Left Most Node in right SubTree
    while(root != NULL && root->left != NULL){
        root = root->left;
    }
    return root;
}
Node* deleteNode(Node* root, int key){
    if(root == NULL){
        return NULL;
    }
    if(key < root->data){
        root->left = deleteNode(root->left,key);
    }
    else if(key > root->data){
        root->right = deleteNode(root->right,key);
    }
    else{
        if(root->left == NULL){
            Node*temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){
            Node*temp = root->left;
            delete root;
            return temp;
        }
        else{
            Node *IS = getInorderSuccessor(root->right);
            root->data = IS->data;
            root->right = deleteNode(root->right,key);
        }
    }
    return root;
}
int main(){
    vector<int> vec = {3,2,1,5,6,4};
    Node *root = BuildTree(vec);
    InOrder(root);
    cout<<endl;
    root = deleteNode(root,1);
    InOrder(root);
    return 0;
}