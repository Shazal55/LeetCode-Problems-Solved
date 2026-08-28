#include <iostream>
#include <vector>
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

vector<int> MorisInOrderTraversal(Node *root){ //O(n)
    vector<int> ans;
    Node *curr = root;
    
    while(curr != NULL)
    {
        if(curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *IP = curr->left;
            while(IP->right != NULL && IP->right != curr)
            {
                IP = IP->right;
            }
            if(IP->right == NULL)
            {
                IP->right = curr; //Create
                curr = curr->left;
            }
            else
            {
                IP->right = NULL; //Destroy
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}
int main(){
    vector<int> vec = {1, -1, 2, 3, -1, -1, -1};
    Node *root = buildTree(vec);
    vector<int> ans = MorisInOrderTraversal(root);
    for(int val : ans)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}
//Output : 1 3 2