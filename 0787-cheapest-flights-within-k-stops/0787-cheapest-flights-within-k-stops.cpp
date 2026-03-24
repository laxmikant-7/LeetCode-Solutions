class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int,int>>> q;
        q.push({0, {src, 0}}); // steps, {node, cost}

        vector<int> min_cost(n, INT_MAX);
        min_cost[src] = 0;

        while(!q.empty()){
            auto it = q.front(); q.pop();

            int steps = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(steps > k) continue;

            for(auto adjNode : adj[node]){
                int next = adjNode.first;
                int price = adjNode.second;

                if(cost + price < min_cost[next]){
                    min_cost[next] = cost + price;
                    q.push({steps + 1, {next, cost + price}});
                }
            }
        }
        return min_cost[dst] == INT_MAX ? -1 : min_cost[dst];
    }
};