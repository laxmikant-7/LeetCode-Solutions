class Solution {
public:
    int solve(vector<int>& nums,int t,int i){
        if(t==0) return 1;
        if(i==nums.size()-1){
            return (t==nums[nums.size()-1])?1:0;
        }
        int take=0;
        if(nums[i]<=t) take=solve(nums,t-nums[i],i+1);
        int nontake=solve(nums,t,i+1);

        return take+nontake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalsum=0;
        for(int num:nums) totalsum+=num;
        if((totalsum+target)%2) return 0;
        int nt=(totalsum+target)/2;
        return solve(nums,nt,0);
    }
};