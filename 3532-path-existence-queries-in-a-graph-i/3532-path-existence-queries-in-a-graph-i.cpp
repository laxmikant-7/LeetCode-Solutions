class Solution {
public:
    void bfs(int src,unordered_map<int,vector<int>> &m,vector<int> &components,int id){
        queue<int> q;
        q.push(src);
        components[src]=id;
        while(!q.empty()){
            int sz=q.size();
            
            while(sz--){
                int node=q.front();
                q.pop();
                for(auto v:m[node]){
                    if(components[v]==-1){
                        components[v]=id;
                        q.push(v);
                    }
                }

            }
        }     
        return;   
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int mx, vector<vector<int>>& q) {
        unordered_map<int,vector<int>> m;
        vector<bool> ans(q.size(),false);
        int i=0;
        int j=0;
        while(i<n && j<n){
            int sum=abs(nums[j]-nums[i]);
            while(sum>mx){
                i++;
                sum=abs(nums[j]-nums[i]);
            }
            if(i!=j){
            m[i].push_back(j);
            m[j].push_back(i);
            }
            j++;
        }
        vector<int> components(n,-1);
        int id=0;
        for(int i=0;i<n;i++){
            if(components[i]==-1){
                bfs(i,m,components,id);
                id++;
            }
        }
        for(int i=0;i<q.size();i++){
            int src=q[i][0];
            int dest=q[i][1];
            if(src==dest) ans[i]=true;
            else ans[i]=components[src]==components[dest];
        }
        return ans;
    }
};