class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int tcnt=0;
            for(int j=i;j<n;j++){
                if(nums[j]==target) tcnt++;
                if((j-i+1)/2<tcnt) ans++;
            }
        }
     return ans;   
    }
};