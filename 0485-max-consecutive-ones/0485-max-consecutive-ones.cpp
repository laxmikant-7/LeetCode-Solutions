class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0;
        int max_ones=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
            }
            if(nums[i]!=1 || i==nums.size()-1){
                max_ones=max(count,max_ones);
                count=0;
            }
        }
        return max_ones;
    }
};