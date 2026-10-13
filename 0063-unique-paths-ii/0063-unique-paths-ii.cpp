class Solution {
public:
    int func(int  i,int j,int n, int m, vector<vector<int>>&dp, vector<vector<int>>& obstacleGrid){
        // Base Cases
        if(i>=m || j>=n) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(i==m-1 && j==n-1) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        int down= func(i+1,j,n,m,dp,obstacleGrid);
        int right= func(i,j+1,n,m,dp,obstacleGrid);

        return dp[i][j]=down+right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(0,0,m,n,dp,obstacleGrid);
    }
};