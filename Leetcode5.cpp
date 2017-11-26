class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        bool f[n][n]={0};
        int longdrome{1},start{0};
        for(int i=0;i<n;++i){
            for(int j=0;j<=i;++j){
                f[j][i]=(s[i]==s[j]&&(i - j < 2 || f[j + 1][i - 1]))||(i==j);
                if(f[j][i]&&longdrome<(i-j+1)){
                    longdrome = i-j+1;
                    start = j;
                }
            }
        }
        return s.substr(start,longdrome);
    }
};