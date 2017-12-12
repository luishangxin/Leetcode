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
    TreeNode *first=nullptr,*second=nullptr;
    TreeNode *prev=new TreeNode(INT_MIN);
public:
    void recoverTree(TreeNode* root) {
        findnode(root);
        swap(first->val,second->val);
    }
    
    void findnode(TreeNode* root){
        if(root==nullptr)return;
        findnode(root->left);
        if(first==nullptr&&prev->val>=root->val)first=prev;
        if(first!=nullptr&&prev->val>=root->val)second=root;
        prev=root;
        findnode(root->right);
    }
};