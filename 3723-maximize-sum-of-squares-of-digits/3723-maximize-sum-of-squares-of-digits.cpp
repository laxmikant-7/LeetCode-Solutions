class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>num*9) return "";
        int no_nines=sum/9;
        int rem=sum%9;

        string ans="";

        while(no_nines){
            ans.push_back('9');
            no_nines--;
        }
        if(rem>0) ans.push_back(rem+'0');
        int need_zeros=num-ans.size();
        if(need_zeros>0){
            while(need_zeros){
                ans.push_back('0');
                need_zeros--;
            }
        }

        return ans;
    }
};