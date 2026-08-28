class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }

        while(!mp.empty()){
            int curr=mp.begin()->first;

            for(int i=0;i<k; i++){
                if(mp[curr+i]==0){
                    return false;
                }
                mp[curr+i]--;
                if(mp[curr+i]==0) mp.erase(curr+i);
            }
        }
        return true;
    }
};