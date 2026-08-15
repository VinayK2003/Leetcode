class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorall=0;
        for(int i=0;i<nums.size();i++) xorall^=nums[i];

        // Here xorall contains the xor of the unique numbers
        // that means xorall will contain ateast one 1 since numbers are unique and diff bits xor give 1. 
        // lb will be having a differntiating bit 
        long long lb= xorall & -xorall;
        int unique1=0;
        for(int i=0;i<nums.size();i++){
            // Grouping all the numbers having that diff bit , duplicate ones will cancel out 
            //and we will get unique1
            if(nums[i]&lb) unique1 ^= nums[i];
        }

        int unique2= xorall ^ unique1;

        return {unique1,unique2};
    }
};