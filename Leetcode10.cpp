class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty())return s.empty();
        if(!s.empty()&&(p[0]==s[0]||p[0]=='.')){
            if(p[1]=='*'){
                return (isMatch(s,p.substr(2)))||(isMatch(s.substr(1),p));
            }
            return isMatch(s.substr(1),p.substr(1));
        }else{
            if(!p.empty()&&p[1]=='*'){
                return isMatch(s,p.substr(2));
            }
            return false;
        }
    }
};