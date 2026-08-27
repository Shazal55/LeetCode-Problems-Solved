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
    void allPaths(vector<string> &paths, string path, TreeNode* root){
        if(root->left == NULL && root->right == NULL){
            paths.push_back(path);
            return;
        }
        if(root->left){
            allPaths(paths, path + "->" + to_string(root->left->val) , root->left);
        }
        if(root->right){
            allPaths(paths, path + "->" + to_string(root->right->val) , root->right);
        }
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string path = to_string(root->val);
        allPaths(paths,path,root);
        return paths;
    }
};