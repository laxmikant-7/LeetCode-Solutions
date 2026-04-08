class Solution {
public:
    int solve(vector<int>& nums,int i,int t,int c){
        if(i==0){
            int temp=0;
            if(c+nums[0]==t) temp++;
            if(c-nums[0]==t) temp++;
            return temp;
        }
        int pos=solve(nums,i-1,t,c+nums[i]);
        int neg=solve(nums,i-1,t,c-nums[i]);

        return pos+neg;
        
    
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int count=0;
        return solve(nums,n-1,target,count);
    }
};