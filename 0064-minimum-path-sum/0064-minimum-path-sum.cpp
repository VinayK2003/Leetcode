class Solution {
public:

    int func(int i,int j, int n,int m,vector<vector<int>>& dp, vector<vector<int>>& grid){

        if(i==n-1 && j==m-1) return grid[i][j];
        if(i>n-1 || j>m-1) return 100000;
        if(dp[i][j]!=-1) return dp[i][j];

        int right= grid[i][j]+func(i,j+1,n,m,dp,grid);
        int down= grid[i][j]+ func(i+1,j,n,m,dp,grid);

        return dp[i][j]=min(down,right); 
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        return func(0,0,n,m,dp,grid);
    }
};