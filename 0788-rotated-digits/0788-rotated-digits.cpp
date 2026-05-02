class Solution {
public:
    bool valid(int n){
        if(n==0) return true;
        int d=n%10;
        if(d==3 || d==4 || d==7) return false;
        return valid(n/10);
    }
    int rotate(int n){
        int p=1;
        int ans=0;
        while(n>0){
            int d=n%10;
            if(d==2) d=5;
            else if(d==5) d=2;
            else if(d==6) d=9;
            else if(d==9) d=6;
            ans+=(d*p);
            p*=10;
            n/=10;
        }
        return ans;
    }
    int rotatedDigits(int n) {
        int count=0;
        for(int i=0;i<=n;i++){
            if(valid(i)){
                int temp=rotate(i);
                if(i!=temp) count++;
            }
        }
        return count;
    }
};