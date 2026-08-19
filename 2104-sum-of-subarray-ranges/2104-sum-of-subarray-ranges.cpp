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

    vector<int> findpgee(vector<int>&arr){
        stack<int>st;
        vector<int>ans(arr.size());
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
     vector<int> findnge(vector<int>&arr){
        stack<int>st;
        vector<int>ans(arr.size());
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            ans[i]=st.empty()?arr.size():st.top();
            st.push(i);
        }
        return ans;
    }

    long long findmaxsums(vector<int>&arr){
        vector<int>nge=findnge(arr);
        vector<int>pgee=findpgee(arr);

        long long sum=0;
        for(int i=0;i<arr.size();i++){
            int left=i-pgee[i];
            int right=nge[i]-i;

            sum+=(1LL*left*right*arr[i]);
        }
        return sum;
    }

    long long findminsums(vector<int>&arr){
        vector<int>nse=findnse(arr);
        vector<int>psee=findpsee(arr);

        long long sum=0;
        for(int i=0;i<arr.size();i++){
            int left=i-psee[i];
            int right=nse[i]-i;

            sum+=(1LL*left*right*arr[i]);
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& arr) {
        long long minsum=findminsums(arr);
        long long maxsum=findmaxsums(arr);

        return maxsum-minsum;
    }
};