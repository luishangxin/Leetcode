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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> s;
        queue<TreeNode*> sta;
        vector<int> t;
        bool change = true;

        if(root)sta.push(root);
        while (sta.size())
        {
            auto nums = sta.size();
            for (int i=0;i<nums;++i)
            {
                auto p = sta.front();
                sta.pop();
                if(p){
                    t.push_back(p->val);
                    if (p->left)sta.push(p->left);
                    if (p->right)sta.push(p->right);
                }
            }
            if(!change){
                reverse(t.begin(),t.end());
            }
            change = !change;
            s.push_back(t);
            t.clear();
        }
        return s;
    }
};