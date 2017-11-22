class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0)return 0;
        for(int i=0;i<haystack.size();++i){
            if(haystack[i]==needle[0]){
                int temp = i+1,j=1;
                while(haystack[temp]==needle[j]&&j<needle.size()&&temp<haystack.size()){
                    temp++,j++;
                }
                if(j==needle.size())return i;
            }
        }
        return -1;
    }
};