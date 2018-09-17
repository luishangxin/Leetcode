class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty())
            return;
        int r=nums.size()-1;
        int ti,tj;
        for(ti=r;ti>0;--ti){
            if(nums[ti-1]<nums[ti]){
                ti=ti-1;
                break;
            }
        }
        for(tj=r;tj>ti;--tj){
            if(nums[ti]<nums[tj])
                break;
        }

        swap(nums[ti],nums[tj]);
        
        if(ti==tj)
            ti=ti-1;
        while((ti+1)!=r&&ti<r){
            swap(nums[ti+1],nums[r--]);
            ti++;
        }
        
    }
};