class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        sort_num = sorted(nums)
        inter = 0
        while inter < len(sort_num)-2:
            flag = -sort_num[inter]
            i = inter + 1
            j = len(sort_num) - 1
            while i<j:
                if sort_num[i] + sort_num[j] > flag:
                    j = j - 1
                elif sort_num[i] + sort_num[j] < flag:
                    i = i + 1
                else:
                    result.append([-flag,sort_num[i],sort_num[j]])                   
                    i = i + 1
                    j = j - 1
                    while i<j and sort_num[i] == sort_num[i-1]:
                    	i += 1
                    while i<j and sort_num[j] == sort_num[j+1]:
                        j -= 1
            while inter < len(sort_num)-2 and sort_num[inter] == sort_num[inter+1]:
                inter += 1
            inter += 1
        return result