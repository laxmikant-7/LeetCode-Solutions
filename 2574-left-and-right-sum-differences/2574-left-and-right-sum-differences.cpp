class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int rsum=0;
        int n=nums.size();
        for(auto num:nums){
            rsum+=num;
        }
        int lsum=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            rsum-=nums[i];
            ans.push_back(abs(lsum-rsum));
            lsum+=nums[i];
        }
        return ans;
    }
};