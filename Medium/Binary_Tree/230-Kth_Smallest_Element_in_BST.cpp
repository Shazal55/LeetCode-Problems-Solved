#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int order = 0;
public:
    void inorder(TreeNode* root,vector<int> &vec){
        if(root == NULL){
            return ;
        }
        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> order;
        inorder(root,order);
        return order[k-1];
    }

    //Optimized solution
    int kthSmallest1(TreeNode* root, int k) {
        if(root == NULL){
            return -1;
        }
        if(root->left){
            int leftAns = kthSmallest1(root->left,k);
            if(leftAns != -1){
                return leftAns;
            }
        }
        if(order + 1 == k){
            return root->val;
        }
        order++;
        if(root->right){
            int rightAns = kthSmallest1(root->right,k);
            if(rightAns != -1){
                return rightAns;
            }
        }
        return -1;
    }
};