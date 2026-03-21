class Solution {
public:
    bool isCyclic(int src,vector<int> arr[],vector<int> &vis,vector<int> &path){
        vis[src]=1;
        path[src]=1;
        for(auto nigh:arr[src]){
            if(!vis[nigh]){
                if(isCyclic(nigh,arr,vis,path)) return true;
            }
            else if(path[nigh]){
                return true;
            }
        }
        path[src]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> arr[n];
        for(auto &pair:p){
            int u=pair[1];
            int v=pair[0];
            arr[u].push_back(v);
        }
        vector<int> vis(n,0);
        vector<int> path(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(isCyclic(i,arr,vis,path)) return false;
            }
        }
        return true;
    }
};