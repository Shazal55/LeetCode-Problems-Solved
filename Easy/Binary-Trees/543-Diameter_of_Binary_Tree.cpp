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
    int height(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) { //TC : O(n)
        if(root == NULL){
            return 0;
        }
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        int currentDiameter = height(root->left) + height(root->right);
        return max(max(leftDiameter,rightDiameter),currentDiameter);
    }

    //Optimized Solution
    int ans = 0;
    int height1(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        ans = max(ans,left+right);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree1(TreeNode* root) {//TC : O(n)
        height(root);
        return ans;
    }
};