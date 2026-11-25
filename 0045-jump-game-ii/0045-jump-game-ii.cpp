class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,j=0;
        while(r<n-1){
            int f=0;
            for(int idx=l;idx<=r;idx++){
                f=max(f,idx+nums[idx]);
            }
            l=r+1;
            r=f;
            j++;
        }
        return j;
    }
};