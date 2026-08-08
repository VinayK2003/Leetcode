class Solution {
public:
    vector<vector<int>>ans;

    void helper(int i,int k, int n,int sum, vector<int>&ds){
        if(k==0){
            if(sum==n){
                ans.push_back(ds);
            }
            return ;
        }
        
        if(i==10) return;
        if(k<0) return;
        if(sum>n) return ;

        

        //pick
        ds.push_back(i);
        helper(i+1,k-1,n,sum+i,ds);
        ds.pop_back();

        //not-pick
        helper(i+1,k,n,sum,ds);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ds;
        int sum=0;
        int i=1;
        helper(i,k,n,sum,ds);
        return ans;
    }
};