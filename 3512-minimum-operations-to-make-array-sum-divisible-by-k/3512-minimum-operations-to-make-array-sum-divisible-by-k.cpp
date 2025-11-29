class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum=0;
        for(int num:nums){
            sum+=num;
        }
        if(sum<k){
            return sum;
        }
        else if(sum==k) return 0;
        
        return sum%k;
    }
};