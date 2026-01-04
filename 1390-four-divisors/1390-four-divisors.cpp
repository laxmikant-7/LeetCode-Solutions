class Solution {
public:

    int findSum(int num){
        int sum=0;
        int count=0;
        for(int i=1;i<=sqrt(num);i++){
            if(num%i==0){
                int other=num/i;
                if(i==other){
                    count++;
                }
                else{
                    count+=2;
                }
                sum+=(i+other);
            }
            if(count>4){
                return 0;
            }
        }
        return (count==4)? sum:0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int res=0;
        for(auto num:nums){
            res+=findSum(num);
        }
        return res;
    }
};