class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MAX;
        int i=0,j=k-1;
        sort(nums.begin(),nums.end());
        while(j<n){
            int min_no=nums[i];
            int max_no=nums[j];
            ans=min(ans,max_no-min_no);
            i++;
            j++;
        }
        return ans;
    }
};