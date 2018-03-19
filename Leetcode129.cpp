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
    int sumNumbers(TreeNode* root) {
        return dsf(root,0);
    }
    
    int dsf(TreeNode* root, int sum){
        if(nullptr==root)return 0;
        if(nullptr==root->left&&nullptr==root->right)
            return 10*sum+root->val;
        
        return dsf(root->left,sum*10+root->val)+dsf(root->right,sum*10+root->val);
    }
};
