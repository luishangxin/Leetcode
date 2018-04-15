class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())return 0;
        if(nums.size()==1)return nums[0];
        int sum=INT_MIN;
        int f[nums.size()]{0};
        f[0]=nums[0];
        sum = f[1]=max(nums[0],nums[1]);

        for(int i=2;i<nums.size();++i){
            f[i]=max(f[i-1],nums[i]+f[i-2]);
            if(f[i]>sum)sum=f[i];
        }
        return sum;
    }
};