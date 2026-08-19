class Solution {
public:

    long long MOD=1e9 + 7;

    vector<int> findnse(vector<int>&arr){
        stack<int>st;
        vector<int>ans(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?arr.size():st.top();
            st.push(i);
        }
        return ans;
    }


    vector<int> findpsee(vector<int>&arr){
        stack<int>st;
        vector<int>ans(arr.size());
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int>nse=findnse(arr);
        vector<int>psee=findpsee(arr);

        int ans=0;

        for(int i=0;i<arr.size();i++){
            int left=i-psee[i];
            int right=nse[i]-i;
            long long contribution= (1LL*left*right*arr[i])%MOD;
            ans=(ans+contribution)%MOD;
        }

        return ans;
    }
};