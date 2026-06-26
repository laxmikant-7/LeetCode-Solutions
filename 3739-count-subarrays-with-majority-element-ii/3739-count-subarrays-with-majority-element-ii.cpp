class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int currsum=0;
        mp[0]=1;
        long long lp=0;
        long long res=0;
        for(int j=0;j<n;j++){
            if(nums[j]==target){
                lp+=mp[currsum];
                currsum+=1;
            }
            else{
                currsum-=1;
                lp-=mp[currsum];
            }
            mp[currsum]+=1;
            res+=lp;
        }
        return res;
    }
};