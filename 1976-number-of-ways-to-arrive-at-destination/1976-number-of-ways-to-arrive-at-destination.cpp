class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        int M=1e9+7;
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int time=it[2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<int> ways(n,0);
        vector<long long> mintime(n, LLONG_MAX);
        ways[0]=1;
        mintime[0]=0;
        pq.push({0,0});//time,node
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            long long currtime=it.first;
            for(auto adjnode:adj[node]){
                long long ntime=adjnode.second+currtime;
                int nnode=adjnode.first;
                if(ntime<mintime[nnode]){
                    mintime[nnode]=ntime;
                    pq.push({ntime,nnode});
                    ways[nnode]=ways[node];
                }
                else if(ntime==mintime[nnode]){
                    ways[nnode]=(ways[nnode]+ways[node])%M;
                }
            }
        }
        return ways[n-1]%M;
    }
};