class Solution {
public:

    void generate(vector<string>&ans,string curr, int open, int close, int n){
        if(curr.size()==2*n){
            ans.push_back(curr);
            return ;
        }
        if(open<n) generate(ans,curr+"(",open+1,close,n);
        if(close<open) generate(ans,curr+")",open,close+1,n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string curr="";
        generate(ans,curr,0,0,n);
        return ans;
    }
};