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
//In-Order Traversal
//left - root - right
void inOrderPrint(Node *root){ //TC : O(n)
    if(root == NULL){
        return;
    }
    inOrderPrint(root->left);
    cout<<root->data<<" ";
    inOrderPrint(root->right);
}

//Post-Order Traversal
// left - right - root
void postOrderPrint(Node *root){ //O(n)
    if(root == NULL)return;
    postOrderPrint(root->left);
    postOrderPrint(root->right);
    cout<<root->data<<" ";
}

//Level-Order Traversal --- Iterative appraoch
void levelOrderPrint(Node *root){ //TC : O(n)
    queue<Node*> q;
    q.push(root);
    while(q.size()>0){
        Node* current = q.front();
        q.pop();
        cout<<current->data<<" ";
        if(current->left != NULL){
            q.push(current->left);
        }
        if(current->right != NULL){
            q.push(current->right);
        }
    }
    cout<<endl;
}
//Print on each line
void levelOrderPrint1(Node *root){ //TC : O(n)
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(q.size()>0){
        Node* current = q.front();
        q.pop();
        if(current == NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }
            else{
                break;
            }
        }
        cout<<current->data<<" ";
        if(current->left != NULL){
            q.push(current->left);
        }
        if(current->right != NULL){
            q.push(current->right);
        }
    }
    cout<<endl;
}

int heightofTree(Node *root){
    if(root == NULL){
        return 0;
    }
    int left = heightofTree(root->left);
    int right = heightofTree(root->right);
    return max(left,right)+1;
}
int countNodes(Node* root) {
    if(root == NULL){
        return 0;
    }
    int left = countNodes(root->left);
    int right = countNodes(root->right);
    return (left+right)+1;
}

int SumOfNodes(Node *root){
    if(root == NULL){
        return 0;
    }
    int leftSum = SumOfNodes(root->left);
    int rightSum = SumOfNodes(root->right);
    return leftSum + rightSum + root->data;
}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node *root = buildTree(preorder);
    cout<<"Sum of Nodes : "<<SumOfNodes(root)<<endl;


    return 0; 
}