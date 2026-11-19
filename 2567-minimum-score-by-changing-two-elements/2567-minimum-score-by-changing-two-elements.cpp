class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        if(n==3) return 0;
        sort(nums.begin(),nums.end());
        int temp1=abs(nums[n-2]-nums[1]);
        int temp2=abs(nums[n-1]-nums[2]);
        int temp3=abs(nums[0]-nums[n-3]);
        return min({temp1,temp2,temp3});
    }
};