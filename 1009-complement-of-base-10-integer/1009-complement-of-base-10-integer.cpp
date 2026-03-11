class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int ans=0;
        int p=0;
        while(n>0){
            int rem=n&1;
            if(!rem){
                ans+=(1<<p);
            }
            p++;
            n/=2;
        }
        return ans;
    }
};