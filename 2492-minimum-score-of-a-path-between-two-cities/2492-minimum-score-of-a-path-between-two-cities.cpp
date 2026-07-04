class Solution {
public:
    int ans=INT_MAX;
    void solve(unordered_map<int,vector<pair<int,int>>> &m,int src,int &ans,vector<bool> &vis){
        vis[src]=true;
        for(auto p:m[src]){
            int v=p.first;
            int d=p.second;
            ans=min(ans,d);
            if(!vis[v]){
                solve(m,v,ans,vis);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> m;
        for(auto &it:roads){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            m[u].push_back({v,w});
            m[v].push_back({u,w});
        }
        vector<bool> vis(n+1,false);
        solve(m,1,ans,vis);
        return ans;
    }
};