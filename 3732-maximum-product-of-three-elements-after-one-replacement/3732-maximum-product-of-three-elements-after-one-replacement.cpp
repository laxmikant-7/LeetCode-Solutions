class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n=nums.size();
        for(auto &x:nums){
            x=abs(x);
        }
        sort(nums.begin(),nums.end());
        return (long long)nums[n-1]*(long long)nums[n-2]*100000;
           }
};