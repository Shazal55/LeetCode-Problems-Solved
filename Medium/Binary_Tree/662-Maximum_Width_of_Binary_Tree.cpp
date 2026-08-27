#include <iostream>
#include <vector>
#include <queue>
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        int maximumWidth = 0;

        while(q.size()>0){
            int currentSize = q.size();
            unsigned long long stIdx =  q.front().second;
            unsigned long long endIdx = q.back().second;

            maximumWidth = max(maximumWidth, (int)(endIdx - stIdx + 1));

            for(int i = 0; i<currentSize; i++){
                auto current = q.front();
                q.pop();
                if(current.first->left){
                    q.push({current.first->left,current.second*2+1});
                }
                if(current.first->right){
                    q.push({current.first->right, current.second*2 + 2});
                }
            }
        }
        return maximumWidth;
    }
};
