class Solution {
public:
    void dfs(unordered_map<int,vector<int>> &m,int src,vector<bool> &vis,vector<bool> &bug,vector<int> &ind){
        bug[src]=true;
        vis[src]=true;
        for(auto node:m[src]){
            ind[node]--;
            if(!vis[node]) dfs(m,node,vis,bug,ind);
        }
        return;
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int,vector<int>> m;
        vector<bool> bug(n,false);
        vector<bool> vis(n,false);
        vector<int> ind(n,0);
        for(auto &e:invocations){
            int u=e[0];
            int v=e[1];
            m[u].push_back(v);
            ind[v]++;
        }
        vector<int> ans;
        dfs(m,k,vis,bug,ind);
        for(int i=0;i<n;i++){
            if(bug[i] && ind[i]>0){
                for(int i=0;i<n;i++) ans.push_back(i);
                return ans;
            }
        }
        for(int i=0;i<n;i++){
            if(!bug[i]) ans.push_back(i);
        }

        return ans;
    }
};