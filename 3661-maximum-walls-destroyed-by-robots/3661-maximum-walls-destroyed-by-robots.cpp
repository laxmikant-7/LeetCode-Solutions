class Solution {
public:
    int count(vector<int> &walls,int i,int j){
        auto it1 = lower_bound(walls.begin(), walls.end(), i);
        auto it2 = upper_bound(walls.begin(), walls.end(), j);
        int lb=it1-walls.begin();
        int up=it2-walls.begin();
        return up-lb;
    }
    int solve(vector<pair<int,int>> &robodist,vector<pair<int,int>> &range,vector<int> &walls,int i,int prevdir,vector<vector<int>> &dp){
        if(i==robodist.size()){
            return 0;
        }

        if(dp[i][prevdir]!=-1) return dp[i][prevdir];

        int leftstart=range[i].first;
        if(prevdir==1){
            leftstart=max(leftstart,range[i-1].second+1);
        }

        int lefttake=count(walls,leftstart,robodist[i].first)+solve(robodist,range,walls,i+1,0,dp);
        int righttake=count(walls,robodist[i].first,range[i].second)+solve(robodist,range,walls,i+1,1,dp);

        return dp[i][prevdir]=max(lefttake,righttake);
    }

    int maxWalls(vector<int>& rob, vector<int>& dist, vector<int>& walls) {
        int n=rob.size();
        vector<pair<int,int>> robodist;
        vector<pair<int,int>> range;
        for(int i=0;i<n;i++){
            robodist.push_back({rob[i],dist[i]});
        }
        sort(robodist.begin(),robodist.end());
        sort(walls.begin(),walls.end());
        for(int i=0;i<n;i++){
            int pos=robodist[i].first;
            int d=robodist[i].second;

            int Lrange= (i==0) ? 1 :robodist[i-1].first+1;
            int Rrange= (i==n-1) ? 1e9 :robodist[i+1].first-1;

            int L=max(Lrange,pos-d);
            int R=min(Rrange,pos+d);

            range.push_back({L,R});
        }

        vector<vector<int>> dp(n,vector<int>(2,-1));

        return solve(robodist,range,walls,0,0,dp);
    }
};