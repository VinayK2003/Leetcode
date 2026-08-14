class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xor1=(start^goal);
        int count=0;
        while(xor1!=0){
            if(xor1&1==1) count++;
            xor1=xor1>>1;
        }
        return count;
    }
};