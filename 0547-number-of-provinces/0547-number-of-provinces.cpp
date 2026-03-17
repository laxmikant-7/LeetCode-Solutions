class Solution {
public:
    void bfs(unordered_map<int,vector<int>> m,int i,vector<int> &visited){
        queue<int> q;
        q.push(i);
        visited[i]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto nighbrs:m[node]){
                if(!visited[nighbrs]){
                    visited[nighbrs]=1;
                    q.push(nighbrs);
                }
            }
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        unordered_map<int,vector<int>> m;
        vector<int> visited(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    m[i].push_back(j);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                count++;
                bfs(m,i,visited);
            }
        }
        return count;
    }
};