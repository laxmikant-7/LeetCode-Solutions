class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int positive_pos=0;
        int negative_pos=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[positive_pos]=nums[i];
                positive_pos+=2;
            }
            else{
                continue;
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]<0){
                ans[negative_pos]=nums[i];
                negative_pos+=2;
            }
            else{
                continue;
            }
        }


       
        return ans;
    }
};