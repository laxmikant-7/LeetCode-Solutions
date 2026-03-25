class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int> vis(n,0);
        vis[0]=1;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int room=q.front();
            q.pop();
            for(auto key:rooms[room]){
                if(key==room) continue;
                if(vis[key]==0){
                    vis[key]=1;
                    q.push(key);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0) return false;
        }
        return true;
    }
};