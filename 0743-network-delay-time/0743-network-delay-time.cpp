class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> min_time(n+1,INT_MAX);
        min_time[k]=0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto item=pq.top();
            pq.pop();
            int currtime=item[0];
            int currnode=item[1];
            for(auto adjnode:adj[currnode]){
                int newnode=adjnode.first;
                int newtime=adjnode.second+currtime;
                if(newtime<min_time[newnode]){
                    min_time[newnode]=newtime;
                    pq.push({newtime,newnode});
                }
            }
        }
        int ans=min_time[1];
        for(int i=1;i<n+1;i++){
            if(min_time[i]==INT_MAX) return -1;
            ans=max(ans,min_time[i]);
        }
        return ans;
    }
};