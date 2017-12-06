class Solution {
public:
    int lengthOfLastWord(string s) {
        auto f=find_if(s.rbegin(),s.rend(),::isalpha);
        auto l=find_if_not(f,s.rend(),::isalpha);
        return distance(f,l);
    }
};