class Solution {
public:
    // int solve(int i,vector<int> &presum,vector<int> &dp){
    //     if(i==presum.size()-1) return presum[i];
    //     if(dp[i]!=-1) return dp[i];
    //     int take=presum[i]-solve(i+1,presum,dp);
    //     int skip=solve(i+1,presum,dp);
    //     return dp[i]=max(take,skip);
    // }
    int stoneGameVIII(vector<int>& st) {
        int n=st.size();
        vector<int> presum(n);
        vector<int> dp(n);
        presum[0]=st[0];
        for(int i=1;i<n;i++){
            presum[i]=presum[i-1]+st[i];
        }
        dp[n-1]=presum[n-1];
        for(int i=n-2;i>=1;i--){
            int take=presum[i]-dp[i+1];
            int skip=dp[i+1];
            dp[i]=max(take,skip);
        }
        return dp[1];
        //return solve(1,presum,dp);
    }
};