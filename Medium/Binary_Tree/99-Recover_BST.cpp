#include <iostream>
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
public:
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    void helper(TreeNode* root){
        if(root == NULL){
            return;
        }
        helper(root->left);
        if(prev != NULL && root->val < prev->val){
            if(!first){
                first = prev;
            }
            second = root;
        }
        prev = root;
        helper(root->right);

    }
    void recoverTree(TreeNode* root) {
        helper(root);
        swap(first->val,second->val);
    }
};