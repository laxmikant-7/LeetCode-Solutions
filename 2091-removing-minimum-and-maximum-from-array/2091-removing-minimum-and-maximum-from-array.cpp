class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return n;
        int low_idx=0,high_idx=0;
        int low_val=INT_MAX;
        int high_val=INT_MIN;
        for(int i=0;i<n;i++){
            int num=nums[i];
            if(num<low_val){
                low_val=num;
                low_idx=i;
            }
            if(num>high_val){
                high_val=num;
                high_idx=i;
            }
        }
        int way1=min(high_idx,low_idx)+1+(n-max(low_idx,high_idx));
        int way2=max(low_idx,high_idx)+1;
        int way3=n-min(low_idx,high_idx);
        return min({way1,way2,way3});
    }
};