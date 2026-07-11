class Solution {
public:
    bool iscomplete(int i,vector<bool> &vis,unordered_map<int,vector<int>> m){
        queue<int> q;
        q.push(i);
        vis[i]=true;
        int nodes=1;
        int edges=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int node=q.front();
                q.pop();
                for(auto it:m[node]){
                    if(!vis[it]){
                        nodes++;
                        vis[it]=true;
                        q.push(it);
                    }
                    edges++;
                }
            }
        }
        return edges==nodes*(nodes-1);
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> m;
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            m[u].push_back(v);
            m[v].push_back(u);
        }
        vector<bool> vis(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(iscomplete(i,vis,m)) count++;
            }
        }
        return count;
    }
};