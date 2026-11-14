class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sub_sz=j-i+1;
                if(sub_sz>=l && sub_sz<=r){
                    int temp=0;
                    for(int k=i;k<=j;k++){
                        temp+=nums[k];
                    }
                    if(temp>0) ans=min(ans,temp);
                }
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};