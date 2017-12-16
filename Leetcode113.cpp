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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(root==nullptr)return res;
        vector<int> path;
        subpathSum(root,sum,path,res);
        return res;
    }
    
    void subpathSum(TreeNode* root, int sum, vector<int> &path,vector<vector<int>> &res){
        if(root==nullptr)return;
        path.push_back(root->val);
        if(root->val==sum&&root->left==nullptr&&root->right==nullptr){
            res.push_back(path);
        }
        if(root->left)subpathSum(root->left,sum-root->val,path,res);
        if(root->right)subpathSum(root->right,sum-root->val,path,res);
        path.pop_back();
    }
};