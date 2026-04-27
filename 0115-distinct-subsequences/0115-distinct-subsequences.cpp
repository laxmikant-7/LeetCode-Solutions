class Solution {
public:
    int solve(string &s,string &t,int i,int j,vector<vector<int>> &dp){
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int take=0;
        if(s[i]==t[j]){
           take=solve(s,t,i+1,j+1,dp);
        }
        int nontake=solve(s,t,i+1,j,dp);
        return dp[i][j]=take+nontake;
    }
    int numDistinct(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        return solve(s,t,0,0,dp);
    }
};