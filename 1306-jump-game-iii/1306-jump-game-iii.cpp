class Solution {
public:
    bool solve(vector<int> &nums,int i,vector<int> &vis){
        if(i>=nums.size() || i<0) return false;
        if(vis[i]) return false;
        if(!vis[i] && nums[i]==0) return true;
        vis[i]=1;
        bool r=solve(nums,i+nums[i],vis);
        bool l=solve(nums,i-nums[i],vis);
        vis[i]=0;
        return r||l;
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int> vis(n,0);
        return solve(arr,start,vis);
        
    }
};