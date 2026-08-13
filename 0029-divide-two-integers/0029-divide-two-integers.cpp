class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        bool sign=true;
        if(dividend>=0 && divisor<0) sign=false;
        if(dividend<0 && divisor>0) sign=false;

        long n=abs((long)dividend);
        long d=abs((long)divisor);

        long ans=0;
        while(n>=d){
            int cnt=0;
            while(n>=(d<<(cnt+1))){
                cnt++;
            }
            ans+=(1LL<<cnt);
            n-=(d<<cnt);
        }
        if(sign==false && ans>INT_MAX){
            return INT_MIN;
        }
        if(sign==true && ans>INT_MAX){
            return INT_MAX;
        }

        return sign?ans:-ans;
    }
};