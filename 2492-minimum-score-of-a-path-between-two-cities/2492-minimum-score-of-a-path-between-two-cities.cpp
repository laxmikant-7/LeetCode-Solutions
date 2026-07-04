class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> m;
        for(auto &it:roads){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            m[u].push_back({v,w});
            m[v].push_back({u,w});
        }
        int ans=INT_MAX;
        vector<bool> vis(n+1,false);
        queue<int> q;
        q.push(1);
        vis[1]=true;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            vis[u]=true;
            for(auto &adj:m[u]){
                int v=adj.first;
                int w=adj.second;
                ans=min(ans,w);
                if(!vis[v]){
                    q.push(v);
                }
            }
        }
        return ans;
    }
};