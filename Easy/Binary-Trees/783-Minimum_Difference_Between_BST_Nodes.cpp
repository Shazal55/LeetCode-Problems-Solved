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
public:
    void inorder(TreeNode* root,vector<int> &vec){
        if(root == NULL){
            return ;
        }
        inorder(root->left,vec);
        vec.push_back(root->val);
        inorder(root->right,vec);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> nodes;
        inorder(root,nodes);
        int minDistance = INT32_MAX;
        for(int i = 0; i<nodes.size()-1; i++){
            minDistance = min(minDistance, nodes[i+1] - nodes[i]);
        }
   
        return minDistance;
    }

    //Another Solution
    TreeNode* prev = NULL;
    int minDiffInBST1(TreeNode* root) {
        if(root == NULL){
            return INT32_MAX;
        }
        int ans = INT32_MAX;
        if(root->left){
            int leftMin = minDiffInBST1(root->left);
            ans = min(ans,leftMin);
        }
        if(prev != NULL){
            ans = min(ans,root->val - prev->val);
        }
        prev = root;
        if(root->right){
            int rightMin = minDiffInBST1(root->right);
            ans = min(ans,rightMin);
        }
        return ans;
    }
};