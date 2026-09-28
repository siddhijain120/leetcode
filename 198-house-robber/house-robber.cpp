class Solution {
public:
    int MaxSum(int idx, int n, vector<int>&house, vector<int>&dp){
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];

        int robCurr = house[idx] + MaxSum(idx+2, n, house, dp);
        int skipCurr = MaxSum(idx+1, n, house, dp);

        return dp[idx] = max(robCurr, skipCurr);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        int ans = MaxSum(0,n,nums,dp);
        return ans;
    }
};