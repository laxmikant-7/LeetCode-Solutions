class Solution {
public:
    int find(vector<int>& nums,int i,int j,vector<vector<int>> &dp){
        if(i==j) return nums[i];
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take_i=nums[i]+min(find(nums,i+2,j,dp),find(nums,i+1,j-1,dp));
        int take_j=nums[j]+min(find(nums,i+1,j-1,dp),find(nums,i,j-2,dp));
        return dp[i][j]=max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int total_score=0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(auto num:nums) total_score+=num;
        int player1=find(nums,0,n-1,dp);
        int player2=total_score-player1;
        return player1>=player2;
    }
};