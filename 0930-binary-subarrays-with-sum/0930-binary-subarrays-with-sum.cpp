class Solution {
public:
    int find(vector<int>& nums, int goal){
        if(goal < 0) return 0;

        int i = 0;
        int sum = 0;
        int total = 0;

        for(int j = 0; j < nums.size(); j++){

            sum += nums[j];

            while(sum > goal){
                sum -= nums[i];
                i++;
            }

            total += (j - i + 1);
        }

        return total;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int f1=find(nums,goal);
        int f2=find(nums,goal-1);
        return f1-f2;
    }
};