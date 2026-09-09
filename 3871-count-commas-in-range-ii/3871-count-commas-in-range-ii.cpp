class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        long long ans=0;
        long long temp=1000;
        while(temp<=n){
            ans+=(n-temp+1);
            temp*=1000;
        }
        return ans;

        
    }
};