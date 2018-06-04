class NumArray {
    vector<int> arr;
public:
    NumArray(vector<int> nums) {
        int sum=0;
        for(auto &i:nums){
            sum+=i;
            arr.push_back(sum);
        }
    }
    
    int sumRange(int i, int j) {
        return i==0?arr[j]:arr[j]-arr[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */