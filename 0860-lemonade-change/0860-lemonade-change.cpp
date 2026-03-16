class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int ch1=0;
        int ch2=0;
        int ch3=0;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                ch1++;
            }
            else if(bills[i]==10){
                if(ch1==0) return false;
                ch1--;
                ch2++;
            }
            else{
                if(ch1==0 ||(ch2==0 && ch1<3)) return false;
                else if(ch2>0){
                    ch2--;
                    ch1--;
                    ch3++;
                }
                else{
                    ch1-=3;
                    ch3++;
                }
            }
        }
        return true;
    }
};