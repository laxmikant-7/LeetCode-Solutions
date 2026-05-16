class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=50000001;
        for(auto num:nums){
            ans=min(ans,num);
        }
        return ans;
    }
};