class Solution {
public:
    void dfs(int src,unordered_map<int,vector<int>> &m,vector<int> &vis){
        vis[src]=1;
        for(auto nigh:m[src]){
            if(!vis[nigh]){
                dfs(nigh,m,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        unordered_map<int,vector<int>> m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    m[i].push_back(j);
                }
            }
        }
        int count=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,m,vis);
            }
        }
        return count;
    }
};