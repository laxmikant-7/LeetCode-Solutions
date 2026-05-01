class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long sum = 0;
        long f0 = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            f0 += (long)i * nums[i];
        }
        
        long ans = f0;
        long prev = f0;
        for(int k = 1; k < n; k++){
            long curr = prev + sum - (long)n * nums[n - k];
            ans = max(ans, curr);
            prev = curr;
        }
        
        return ans;
    }
};