class Solution {
public:
    int func(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dp){
        if(j<0|| j>matrix[0].size()-1) return 100000;
        if(i==matrix.size()-1) return matrix[i][j];
        if(dp[i][j]!=INT_MIN) return dp[i][j];

        int down= matrix[i][j]+ func(i+1,j,matrix,dp);
        int leftdown=matrix[i][j]+func(i+1,j-1,matrix,dp);
        int rightdown=matrix[i][j]+func(i+1,j+1,matrix,dp);

        return dp[i][j]=min(min(down,leftdown),rightdown);
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MIN));
        for(int i=0;i<matrix[0].size();i++){
            ans=min(ans,func(0,i,matrix,dp));
        }

        return ans;
    }
};