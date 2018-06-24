class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int add=1;
        vector<int> out;
        for(auto i=digits.rbegin();i!=digits.rend();++i){
            if(*i+add>=10){
                out.push_back(*i+add-10);
                add = 1;
            }else{
                out.push_back(*i+add);
                add=0;
            }
        }
        if(add==1)
            out.push_back(1);
        reverse(out.begin(),out.end());
        return out;
    }
};