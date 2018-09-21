class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> out;
        if(nums.empty())
            return vector<int>(2,-1);
        int f = findIndex(nums,target,0,nums.size()-1);

        if(f<0)
            return vector<int>(2,-1);
        int l=f,r=f;
        int lt=f;
        while(1){
            lt = findIndex(nums,target,0,lt-1);
            if(lt>-1)
                l=lt;
            if(lt==-1)
                break;
        }

        int rt=f;
        while(1){
            rt=findIndex(nums,target,rt+1,nums.size()-1);
            if(rt>-1)
                r=rt;
            else
                break;
        }

        out.push_back(l);
        out.push_back(r);      
        return out;
    }
    
    int findIndex(vector<int>& nums, int target,int l,int r){
        if(l>r)
            return -1;
        int mid = (r+l)/2;
        int out=-1;

        if(nums[mid]==target)
            return mid;
        if(nums[mid]>target)
            out=findIndex(nums,target,l,mid-1);
        else
            out=findIndex(nums,target,mid+1,r);
        
        return out;      
    }
};