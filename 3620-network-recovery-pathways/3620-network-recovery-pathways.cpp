class Solution {
public:
    typedef pair<long long,int> P;
    bool valid(int mid,int dest,unordered_map<int,vector<pair<int,int>>> &m,long long k){

        priority_queue<P,vector<P>,greater<P>> pq;
        vector<long long> dist(dest+1,LLONG_MAX);
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            long long d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(node==dest) return d<=k;
            if(d>k) return false;
            if(dist[node]<d) continue;

            for(auto &nigh:m[node]){
                int v=nigh.first;
                long long cost=nigh.second;
                if(cost<mid) continue;
                if(d+cost<dist[v]){
                    dist[v]=d+cost;
                    pq.push({d+cost,v});
                }
            }

        }





    return false;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        unordered_map<int,vector<pair<int,int>>> m;
        int l=INT_MAX;
        int r=INT_MIN;
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];
            bool isonline1=online[u];
            bool isonline2=online[v];
            if(isonline1 && isonline2){
                m[u].push_back({v,w});
                l=min(l,w);
                r=max(r,w);
            }
        }
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(valid(mid,n-1,m,k)){
                ans=max(ans,mid);
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }

        
        return ans;
    }
};