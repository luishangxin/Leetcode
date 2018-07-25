class Solution {
public:
    int numTrees(int n) {
        if(n==0)return 1;
        if(n==1)return 1;
        if(n>1){
            int m = (n+1)/2;
            int sum=0;
            for(int i=0;i<m;++i){
                sum += 2*numTrees(n-1-i)*numTrees(i);
            }
            return (n%2==0)?sum:sum-numTrees(n-m)*numTrees(n-m);
        }
    }
};

// DP
class Solution {
public:
    int numTrees(int n) {
        vector<int> remap(n+1,0);
        remap[0]=1;
        remap[1]=1;
        for(int i=2;i<n+1;++i){
            for(int j=0;j<i;++j){
                remap[i]+=remap[j]*remap[i-j-1];
            }
        }
        return remap[n];
    }
};