class Solution {
public:

    typedef long long ll;

    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>arr;
        int n=nums1.size();
        for(int i=0;i<nums1.size();i++){
            arr.push_back({nums1[i],i,nums2[i]});
        }

        sort(begin(arr),end(arr));

        ll sum=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<ll>ans(n,0);

        for(int i=0;i<n;i++){
            if(i>0 && arr[i][0]==arr[i-1][0]){
                ans[arr[i][1]]=ans[arr[i-1][1]];
            }
            else{
                ans[arr[i][1]]=sum;
            }
                pq.push(arr[i][2]);
                sum+=arr[i][2];
                if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }    
        }
        return ans;
    }
};