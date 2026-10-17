class Solution {
public:

    int func(int i, int sum, vector<int>& coins,vector<vector<int>>&dp){
        if(sum==0) return 1;
        if(i==coins.size()) return 0;
        if(sum<0) return  0;
        
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        //not pick
        int notpick= func(i+1,sum,coins,dp);
        
        int pickagain= func(i,sum-coins[i],coins,dp);
        
        return dp[i][sum]=notpick+pickagain;
    }

    int change(int sum, vector<int>& coins) {
         vector<vector<int>>dp(coins.size(),vector<int>(sum+1,-1));
        return func(0,sum,coins,dp);
    }
};