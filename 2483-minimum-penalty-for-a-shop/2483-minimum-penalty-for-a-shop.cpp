class Solution {
public:
    int bestClosingTime(string cust) {
        int p=0;
        int n=cust.size();
        for(auto c:cust){
            if(c=='Y') p+=0;
            else p+=1;
        }
        int minp=p,ans=n;
        for(int i=n-1;i>=0;i--){
            if(cust[i]=='N'){
                p-=1;
                if(p<=minp){
                    minp=p;
                    ans=i;
                }
            }
            else{
                p+=1;
            }
        }
        return ans;
    }
};