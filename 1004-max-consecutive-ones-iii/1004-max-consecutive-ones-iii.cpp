class Solution {
public:

//  Here we just need to figure out the max subarray with atmost k zeros
    int longestOnes(vector<int>& nums, int k) {
        int maxlen=0;
        int i=0,j=0,n=nums.size();
        int cnt=0;
        while(j<n){
            if(nums[j]==0){
                cnt++;
                while(cnt>k){
                    if(nums[i]==0)cnt--;
                    i++;
                }
            }
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};