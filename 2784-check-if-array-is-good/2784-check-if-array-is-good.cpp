class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=*max_element(nums.begin(),nums.end());
        sort(nums.begin(),nums.end());
        if(nums.size()!=n+1) return false;
        int idx=1;
        for(int i=0;i<n;i++){
            if(idx!=nums[i]) return false;
            idx++;
        }
        return nums[n]==n;
    }
};