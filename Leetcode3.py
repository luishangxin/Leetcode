class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        temp = []
        maxlen = 0
        for i in s:
            if i in temp:
                length = len(temp)
                if length > maxlen:
                    maxlen = length
                temp=temp[temp.index(i)+1:]
            temp.append(i)
        return max(len(temp),maxlen)