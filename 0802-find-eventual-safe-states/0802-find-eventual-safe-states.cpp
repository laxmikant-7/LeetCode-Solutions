class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> arr[n];
        for(int i=0;i<n;i++){
            for(auto nigh:graph[i]){
                arr[nigh].push_back(i);
            }
        }
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto nigh:arr[i]){
                indegree[nigh]++;
            }
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto nigh:arr[node]){
                indegree[nigh]--;
                if(indegree[nigh]==0) q.push(nigh);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};