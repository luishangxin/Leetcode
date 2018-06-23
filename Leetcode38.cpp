class Solution {
public:
    string countAndSay(int n) {
        if(n<=0)return "";
        if(n==1)return "1";
        string out="1";
        for(int i=2;i<=n;i++){
            int num=0;
            auto tmp=out[0];
            string s="";
            for(int j=0;j<out.size();j++){
                if(tmp!=out[j]){
                    s=s+to_string(num)+tmp;
                    tmp=out[j];
                    num=1;
                }else{
                    num++;
                }
                if(j==out.size()-1)
                    s=s+to_string(num)+tmp;
            }
            out=s;
        }
        return out;
    }
};