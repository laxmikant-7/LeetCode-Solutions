class Solution {
public:

    int find(int st,vector<int> &nums,int tr){
        int j=lower_bound(nums.begin()+st,nums.end(),tr)-nums.begin();
        if(j<nums.size() && nums[j]==tr) return j;
        return -1;
    }

    int solve(int i,int inc,vector<int> &nums,vector<vector<int>> &dp){

        if(dp[i][inc]!=-1) return dp[i][inc];

        int currval=nums[i]+inc;
        int len=1;

        int j=find(i+1,nums,currval+1);
        if(j!=-1){
            len=max({len,1+solve(j,0,nums,dp)});
        }

        j=find(i+1,nums,currval);
        if(j!=-1){
            len=max({len,1+solve(j,1,nums,dp)});
        }

        return dp[i][inc]=len;
    }
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=1;
        vector<vector<int>> dp(n,vector<int>(2,-1));
        for(int i=0;i<n;i++){
            ans=max({ans,solve(i,0,nums,dp),solve(i,1,nums,dp)});
        }
        return ans;
    }
};