class Solution {
public:
    int find1(vector<int> &nums){
        int n=nums.size();
        int i=0;
        int j=1;
        int ans=1;
        while(j<n){
            if(nums[j]>nums[j-1]){
            ans=max(ans,j-i+1);
            j++;
            }
            else{
                i=j;
                j++;
            }
        }
        return ans;
    }
    int find2(vector<int> &nums){
        int n=nums.size();
        int i=0;
        int j=1;
        int ans=1;
        while(j<n){
            if(nums[j]<nums[j-1]){
            ans=max(ans,j-i+1);
            j++;
            }
            else{
                i=j;
                j++;
            }
        }
        return ans;
    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=find1(nums);
        int dec=find2(nums);
        return max(inc,dec);
    }
};