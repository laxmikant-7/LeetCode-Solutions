class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> temp(n);
        temp[n-1]=nums[n-1];
        int max_so_far=INT_MIN;
        for(int i=n-2;i>=0;i--){
            temp[i]=min(temp[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            max_so_far=max(max_so_far,nums[i]);
            int score=max_so_far-temp[i];
            if(score<=k) return i;
        }
        return -1;
    }
};