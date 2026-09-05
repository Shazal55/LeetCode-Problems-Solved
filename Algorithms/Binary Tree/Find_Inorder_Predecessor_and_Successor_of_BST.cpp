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
Node* rightMostInLeft(Node* root){
    Node* ans = NULL;
    while(root != NULL){
        ans = root;
        root = root->right;
    }
    return ans;
}
Node* leftMostInRight(Node* root){
    Node* ans = NULL;
    while(root != NULL){
        ans = root;
        root = root->left;
    }
    return ans;
}
vector<int> getPredSuc(Node* root,int key){
    Node* curr = root;
    Node* pred = NULL;
    Node* succ = NULL;
    while(curr != NULL){
        if(key < curr->data){
            succ = curr;
            curr = curr->left;
        }
        else if(key > curr->data){
            pred = curr;
            curr = curr->right;
        }
        else{
            if(curr->left != NULL){
                pred = rightMostInLeft(curr->left);
            }
            if(curr->right != NULL){
                succ = leftMostInRight(curr->right);
            }
            break;
        }
    }
    return {pred->data,succ->data};
}
int main(){
    Node* root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    int key = 7;

    vector<int> ans = getPredSuc(root,key);
    cout<<"Predecessor : "<<ans[0]<<endl;
    cout<<"Successor : "<<ans[1]<<endl;
    return 0;
}
//Output : Predecessor : 6  Successor : 8