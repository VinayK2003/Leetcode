class Solution {
public:

    int func(int i,int j,string & a, string& b,vector<vector<int>>&dp){
        if(i>=a.size() || j>=b.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j]) return dp[i][j]= 1 + func(i+1,j+1,a,b,dp);
        

        int move_a=func(i+1,j,a,b,dp);
        int move_b=func(i,j+1,a,b,dp);

        return dp[i][j]=max(move_a,move_b);

    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        return func(0,0,text1,text2,dp);
    }
};