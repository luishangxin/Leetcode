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
    vector<TreeNode*> l;
public:
    void flatten(TreeNode* root) {
        nodelist(root);
        for(int i=0;i<l.size();++i){
            l[i]->left=nullptr;
            if(i+1<l.size()){
                l[i]->right=l[i+1];
            }
            if(i==l.size()-1){
                l[i]->right=nullptr;
            }
        }
    }
    
    void nodelist(TreeNode* root){
        if(root){
            l.push_back(root);
            if(root->left)nodelist(root->left);
            if(root->right)nodelist(root->right);
        }
    }
};