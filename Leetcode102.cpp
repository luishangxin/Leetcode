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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> temp;
        deque<TreeNode*> s;
        TreeNode *last,*top;
        if(root){
            s.push_back(root);
            last = root;
        }
        while(!s.empty()){
            top = s.front();
            temp.push_back(top->val);
            s.pop_front();
            if(top->left)s.push_back(top->left);
            if(top->right)s.push_back(top->right);
            if(last==top){
                last = s.back();
                res.push_back(temp);
                temp.clear();
            }
        }
        return res;
    }
};