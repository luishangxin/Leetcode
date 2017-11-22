\*In Leetcode.com "+-" "--" prefix is invalid. Be careful.*\
class Solution {
public:
    int myAtoi(string str) {
        if(!str.size())return 0;
        int neg{1};
        int i{0},res{0};
        while(str[i] == ' ' && i < str.size()) i++;
        if(str[i] == '+'||str[i] == '-'){
            neg=(str[i] == '-')?-1:1;
            i++;
        }
        while(i<str.size()){
            if(isdigit(str[i])){
                if(res>INT_MAX/10||res==INT_MAX/10&&(str[i]-'0')>INT_MAX%10){
                    return neg==-1?INT_MIN:INT_MAX;
                }
                res = res*10 + (str[i]-'0');
            }else{
                break;
            }
            ++i;
        }
        return res*neg;
    }
};