class Solution {
public:
    int countSubsets(vector<int>& nums, int i, int sum) {
        if(i == nums.size()) {
            return (sum == 0) ? 1 : 0;
        }
        int take = 0;
        if(nums[i] <= sum)
            take = countSubsets(nums, i + 1, sum - nums[i]);
        int notTake = countSubsets(nums, i + 1, sum);
        return take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for(int x : nums) totalSum += x;
        if(totalSum + target < 0 || (totalSum + target) % 2 != 0)
            return 0;
        int s1 = (totalSum + target) / 2;
        return countSubsets(nums, 0, s1);
    }
};