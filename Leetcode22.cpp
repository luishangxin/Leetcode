class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        string str;
        if(n>=1)
            gen(vec,str,0,0,n);
        return vec;
    }
    
    void gen(vector<string>&vec,string str,int open,int back,int max){
        if(str.size()==2*max){
            vec.push_back(str);
            return;
        }
        if(open<max){
            gen(vec,str+'(',open+1,back,max);
        }
        if(back<open){
            gen(vec,str+')',open,back+1,max);
        }
    }
};