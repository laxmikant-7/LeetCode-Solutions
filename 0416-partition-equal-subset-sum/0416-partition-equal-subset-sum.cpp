class Solution {
public:    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalsum=0;
        for(auto num:nums) totalsum+=num;
        if(totalsum%2!=0) return false;
        int t=totalsum/2;
        vector<vector<bool>> dp(n,vector<bool>(t+1,false));
        for(int i=0;i<n;i++) dp[i][0]=true;
        for(int i=1;i<=t;i++){
            if(nums[0]==i) dp[0][i]=true;
        }
        for(int i=1;i<n;i++){
            for(int tar=1;tar<=t;tar++){
                bool nottake=dp[i-1][tar];
                bool take=false;
                if(nums[i]<=tar){
                    take=dp[i-1][tar-nums[i]];
                }
                dp[i][tar]=(take||nottake);
            }
        }
        return dp[n-1][t];
    }
};