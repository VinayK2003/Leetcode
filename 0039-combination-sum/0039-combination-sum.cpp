class Solution {
public:
    vector<vector<int>>ans;

    void func(vector<int>& arr, int k,int ind,vector<int>&temp){
        if(ind==arr.size()){
            if(k==0) ans.push_back(temp);
            return ;
        }

        if(arr[ind]<=k){
            temp.push_back(arr[ind]);
            func(arr,k-arr[ind],ind,temp);
            temp.pop_back();
        }
        func(arr,k,ind+1,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int k) {
        vector<int>temp;
        func(arr,k,0,temp);
        return ans;
    }
};