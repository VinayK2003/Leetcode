class Solution {
public:

    vector<vector<int>>dp;
    bool func( int ind,int cnt,string s){
        if(cnt<0) return false;
        if(ind==s.size()) return cnt==0;
        if( dp[ind][cnt]!=-1) return dp[ind][cnt];
        if(s[ind]== '(') return dp[ind][cnt] =func(ind+1,cnt+1,s);
        else if(s[ind]==')') return dp[ind][cnt] = func(ind+1,cnt-1,s);

       return dp[ind][cnt] =func(ind+1,cnt+1,s) || func(ind+1,cnt-1,s) || func(ind+1,cnt,s);
    }

    bool checkValidString(string s) {
        //Recursive Approach
        int n = s.size();
        dp.assign(n, vector<int>(n + 1, -1));
        return func(0,0,s);
    }
};