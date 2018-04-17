class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int maxProf = 0;
        if(k>prices.size()/2){
            for(int i=1;i<prices.size();++i){
                maxProf+=max(prices[i]-prices[i-1],0);
            }
            return maxProf;
        }

        vector<vector<int>> f(2, vector<int>(prices.size()+1, 0));
        for (int kk = 1; kk <= k; kk++) {
            int tmpMax = f[(kk-1)%2][0] - prices[0];
            for (int ii = 1; ii < prices.size(); ii++) {
                f[kk%2][ii] = max(f[kk%2][(ii-1)], prices[ii] + tmpMax);
                tmpMax = max(tmpMax, f[(kk-1)%2][ii] - prices[ii]);
                maxProf = max(f[kk%2][ii], maxProf);
            }
        }
        return maxProf;
    }
};

