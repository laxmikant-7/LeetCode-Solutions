class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen=0;
        int n=nums.size();
        int i=0;int j=0;
        int flips=0;
        while(j<n){
            if(nums[j]==0) flips++;
            if(flips>k){
                if(nums[i]==0) flips--;
                i++;
            }
            if(flips<=k){
                maxlen=max(maxlen,j-i+1);
            }
            j++;
        }
        return maxlen;
    }
};