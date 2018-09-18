class Solution {
public:
    int search(vector<int>& nums, int target) {
        return _search(nums,0,nums.size()-1,target);
    }
    
    int _search(vector<int>& nums,int l,int r,int target){
        if(l>r)return -1;
        if(l==r&&nums[l]!=target)
            return -1;
        int mid=(l+r)/2;
        
        if(nums[mid]==target)
            return mid;
        
        int ll = _search(nums,l,mid,target);
        int rr = _search(nums,mid+1,r,target);
        
        return ll>-1?ll:rr>-1?rr:-1;
    }
};