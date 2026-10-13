class Solution {
public:

    int func(int  i,int j,int n, int m, vector<vector<int>>&dp){

        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int down= func(i+1,j,n,m,dp);
        int right= func(i,j+1,n,m,dp);

        return dp[i][j]=down+right;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return func(0,0,n,m,dp);
    }
};