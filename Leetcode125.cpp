class Solution {
public:
    bool isPalindrome(string s) {
        auto left = s.begin(), right = prev(s.end());
	while (left < right) {	 
	    if (!::isalnum(*left)) ++left;	
	    else if (!::isalnum(*right)) --right;
	    else if (tolower(*left++) != tolower(*right--)) return false;
        }
	return true;
    }
};
