class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int c1=0;
        int c0=0;
        int total=-1;
        for(auto ch:s){
            if(ch=='1') c1++;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]=='0'){
                c0++;
            }
            else{
                c1--;
            }
            total=max(total,c0+c1);
        }
        return total;
    }
};