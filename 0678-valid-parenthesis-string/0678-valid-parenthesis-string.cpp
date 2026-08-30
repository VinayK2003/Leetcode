class Solution {
public:

    // vector<vector<int>>dp;
    // bool func( int ind,int cnt,string s){
    //     if(cnt<0) return false;
    //     if(ind==s.size()) return cnt==0;
    //     if( dp[ind][cnt]!=-1) return dp[ind][cnt];
    //     if(s[ind]== '(') return dp[ind][cnt] =func(ind+1,cnt+1,s);
    //     else if(s[ind]==')') return dp[ind][cnt] = func(ind+1,cnt-1,s);

    //    return dp[ind][cnt] =func(ind+1,cnt+1,s) || func(ind+1,cnt-1,s) || func(ind+1,cnt,s);
    // }

    bool checkValidString(string s) {
        //Recursive DP Approach
        // TC:- O(n^2)
        //SC:-O(n^2)
        // int n = s.size();
        // dp.assign(n, vector<int>(n + 1, -1));
        // return func(0,0,s);

        int mini=0,maxi=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                mini++;
                maxi++;
            }
            else if(s[i]==')'){
               mini--;
               maxi--;
            }
            else{
                mini--;
                maxi++;
            }
            if(maxi<0) return false;

            mini=max(mini,0);
        }
        return mini==0;



    }
};