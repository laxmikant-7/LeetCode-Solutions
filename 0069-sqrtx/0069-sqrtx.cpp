class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int l=1,r=x;
        int ans=INT_MIN;
        while(l<=r){
            int mid=l+(r-l)/2;
            if((long)mid*mid>x){
                r=mid-1;
                continue;
            }
            else{
                l=mid+1;
                ans=mid;
            }
        }
        return ans;
    }
};