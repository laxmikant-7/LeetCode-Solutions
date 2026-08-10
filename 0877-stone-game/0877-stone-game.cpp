class Solution {
public:
    // int solve(vector<int> &vec,int i,int j,vector<vector<int>> &dp){
    //     if(i>j) return 0;
    //     if(i==j) return vec[i];
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int take_i=vec[i]+min(solve(vec,i+1,j-1,dp),solve(vec,i+2,j,dp));
    //     int take_j=vec[j]+min(solve(vec,i+1,j-1,dp),solve(vec,i,j-2,dp));
    //     return dp[i][j]=max(take_i,take_j);
    // }
    bool stoneGame(vector<int>& piles) {
        // int total_sum=0;
        // int n=piles.size();
        // for(auto p:piles) total_sum+=p;
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // int alice=solve(piles,0,n-1,dp);
        // int bob=total_sum-alice;
        // return alice>bob;
        return true;
    }
};