class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int cnt=0,sum=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1) sum++;
            if(mp.find(sum-k)!=mp.end()) cnt+=mp[sum-k];
            mp[sum]++;
        }

        return cnt;
    }
};