/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr)return 0;
        if(root->right != nullptr){
            return minDepth(root->left)!=0?min(minDepth(root->left),minDepth(root->right))+1:minDepth(root->right)+1;
        }else{
            return minDepth(root->left)+1;
        }
    }
};