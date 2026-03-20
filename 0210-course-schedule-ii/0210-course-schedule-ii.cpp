class Solution {
public:
    bool dfs(int src,vector<int> arr[],vector<int> &vis,vector<int> &path){
        vis[src]=1;
        path[src]=1;
        for(auto nigh:arr[src]){
            if(!vis[nigh]){
            if(dfs(nigh,arr,vis,path)) return true;
            }
            else if(path[nigh]){
                return true;
            }
        }
        path[src]=0;
        return false;
    }
    void find_topo(int src,vector<int> &vis,stack<int> &st,vector<int> arr[]){
        vis[src]=1;
        for(auto nigh:arr[src]){
            if(!vis[nigh]){
                find_topo(nigh,vis,st,arr);
            }
        }
        st.push(src);
    }
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> arr[n];
        vector<int> ans;
        for(int i=0;i<p.size();i++){
            int u=p[i][1];
            int v=p[i][0];
            arr[u].push_back(v);
        }
        vector<int> vis(n);
        vector<int> path(n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,arr,vis,path)) return {};
            }
        }
        vis.assign(n,0);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                find_topo(i,vis,st,arr);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};