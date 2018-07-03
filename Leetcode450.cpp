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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)return nullptr;
        if(root->val>key)
            root->left=deleteNode(root->left,key);
        if(root->val<key)
            root->right=deleteNode(root->right,key);
        if(root->val==key){
            if(root->left==nullptr||root->right==nullptr){
                root=root->left==nullptr?root->right:root->left;
            }else{
                auto p=root->right;
                while(p->left)p=p->left;
                root->val=p->val;
                root->right=deleteNode(root->right,p->val);
            }
        }
        return root;
    }
};