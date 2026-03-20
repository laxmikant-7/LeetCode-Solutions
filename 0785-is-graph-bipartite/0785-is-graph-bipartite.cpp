class Solution {
public:
    bool dfs(int src,vector<int> &vis,vector<vector<int>>& graph,int val){
        vis[src]=val;
        for(auto nigh:graph[src]){
            if(vis[nigh]==-1){
                if(!dfs(nigh,vis,graph,!val)) return false;
            }
            else if(vis[nigh]==val) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int val=0;
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(!dfs(i,vis,graph,val)) return false;
            }
        }
        return true;
    }
};