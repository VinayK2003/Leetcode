class Solution {
public:
    
    vector<int> findnse(vector<int>&arr){
        stack<int>st;
        vector<int>ans(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?arr.size():st.top();
            st.push(i);
        }
        return ans;
    }

    // find previous smaller or equal element
    vector<int> findpsee(vector<int>&arr){
        stack<int>st;
        vector<int>ans(arr.size());
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& arr) {
        vector<int>nse=findnse(arr);
        vector<int>psee=findpsee(arr);

        int ans=0;
        for(int i=0;i<arr.size();i++){
            int left=i-psee[i];
            int right=nse[i]-i;
            int width=left+right-1;
            int area=width*arr[i];

            ans=max(ans,area);
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>prefixsum(n, vector<int>(m));
        for (int j = 0; j < matrix[0].size(); j++) {
            prefixsum[0][j] = matrix[0][j] - '0';
        }

        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if (matrix[i][j] == '1')
                    prefixsum[i][j] = prefixsum[i-1][j] + 1;
                else
                    prefixsum[i][j] = 0;
            }
        }

        int ans=0;

        for(int i=0;i<prefixsum.size();i++){
                int maxarea=largestRectangleArea(prefixsum[i]);
                ans=max(ans,maxarea);
        }
        return ans;
    }
};