class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans=0;
        for(int i=n;;i++){
            int temp=i;
            int digitsum=1;
            while(temp>0){
                int d=temp%10;
                temp/=10;
                digitsum*=d;
            }
            if(digitsum%t==0){
                ans=i;
                break;
            }
        }
        return ans;
    }
};