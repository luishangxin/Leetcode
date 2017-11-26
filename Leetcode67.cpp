class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int num = a.size()>b.size()?a.size():b.size();
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        int ci{0};
        for(int i=0;i<num;++i){
            int ai = i < a.size() ? a[i] - '0' : 0;
            int bi = i < b.size() ? b[i] - '0' : 0;
            res.insert(res.begin(),ai^bi^ci+'0');
            ci = ai&bi==1?1:(ai^bi)&ci;
        }
        if(ci==1)res.insert(res.begin(),'1');
        return res;
    }
};