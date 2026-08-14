class Solution {
public:
    void sub(vector<int>& nums,int index, vector<vector<int>>&ans, vector<int>&ds,int n){
        if(n==index){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[index]);
        sub(nums,index+1,ans,ds,n);
        ds.pop_back();
         sub(nums,index+1,ans,ds,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
    //     vector<vector<int>>ans;
    //     vector<int>ds;
    //    int n= nums.size();
    //     sub(nums,0,ans,ds,n);
    //     return ans;

        // Bit Approach
        vector<vector<int>>ans;
        int subset=1<<nums.size();
        for(int i=0;i<subset;i++){
            vector<int>ds;
            for(int j=0;j<nums.size();j++){
                if(i&(1<<j)){
                    ds.push_back(nums[j]);
                }
            }
            ans.push_back(ds);
        }
        return ans;
    }
};