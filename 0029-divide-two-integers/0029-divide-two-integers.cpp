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
            int p=0;
            while((d<<(p+1))<=n){
                p++;
            }
            n-=(d<<p);
            ans+=(1<<p);
        }
        if(ans==(1<<31) && sign) return INT_MAX;
        if(ans==(1<<31) && !sign) return INT_MIN;
        return (sign)?ans:-1*ans;
    }
};