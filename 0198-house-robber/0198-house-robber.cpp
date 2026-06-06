class Solution {
public:
    // int find(int i,vector<int> &nums,vector<int> &dp){
    //     if(i>=nums.size()-1) return 0;
    //     if(i==nums.size()-1) return nums[i];
    //     if(dp[i]!=-1) return dp[i];
    //     int take=nums[i]+find(i+2,nums,dp);
    //     int nontake=find(i+1,nums,dp);
    //     return dp[i]=max(take,nontake);
    // }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        // return find(0,nums,dp);
        dp[0]=nums[0];
        int neg=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take+=dp[i-2];
            int nontake=dp[i-1];
            dp[i]=max(take,nontake);
        }
        return dp[n-1];
    }
};