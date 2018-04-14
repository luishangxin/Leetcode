/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        queue<UndirectedGraphNode*> q,q1;
        map<UndirectedGraphNode*,UndirectedGraphNode*> hash_m;
        
        if(node==nullptr)return nullptr;
        q.push(node);
        
        UndirectedGraphNode* out=new UndirectedGraphNode(node->label);
        q1.push(out);
        hash_m.insert(pair<UndirectedGraphNode*,UndirectedGraphNode*>(node,out));

        while(!q.empty()){
            auto tmp=q.front();
            auto tmp1=q1.front();
            if(!tmp->neighbors.empty()){
                for(auto i:tmp->neighbors){
                    auto it=hash_m.find(i);
                    if(it==hash_m.end()){
                        q.push(i);
                        auto q1_it=new UndirectedGraphNode(i->label);
                        q1.push(q1_it);
                        tmp1->neighbors.push_back(q1_it);
                        hash_m.insert(pair<UndirectedGraphNode*,UndirectedGraphNode*>(i,q1_it));
                    }else{
                        tmp1->neighbors.push_back(it->second);
                    }
                }
            }
            q.pop();
            q1.pop();
        }
        
        return out;
    }
};