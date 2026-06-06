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
        // return find(0,nums,dp);
        int p1=nums[0];
        int p2=nums[0];
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) {
                take+=p1;
                p1=p2;
                }
            int nontake=p2;
            p2=max(take,nontake);
        }
        return p2;
    }
};