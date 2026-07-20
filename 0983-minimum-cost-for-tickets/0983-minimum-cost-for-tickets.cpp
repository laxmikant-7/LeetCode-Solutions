class Solution {
public:
    int solve(int i,vector<int>& days, vector<int>& costs,vector<int> &dp){
        if(i>=days.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int pass1=costs[0]+solve(i+1,days,costs,dp);
        int mxday1=days[i]+7;
        int j=i;
        while(j<days.size() && days[j]<mxday1) j++;
        int pass2=costs[1]+solve(j,days,costs,dp);
        int mxday2=days[i]+30;
        int k=i;
        while(k<days.size() && days[k]<mxday2) k++;
        int pass3=costs[2]+solve(k,days,costs,dp);
        return dp[i]=min(pass1,min(pass2,pass3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366,-1);

        return solve(0,days,costs,dp);
        
    }
};