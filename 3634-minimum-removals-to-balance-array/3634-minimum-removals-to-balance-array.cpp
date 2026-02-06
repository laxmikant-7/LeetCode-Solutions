class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        int j=0;
        int L=1;
        while(j<n){
            int mini=nums[i];
            int maxi=nums[j];
            while(maxi>(long long)mini*k){
                i++;
                mini=nums[i];
            }
            L=max(L,j-i+1);
            j++;
        }
        return n-L;
    }
};