class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            int curr_num=abs(nums[i]);
            if(nums[curr_num-1]<0){
                ans.push_back(curr_num);
            }
            else{
                nums[curr_num-1]*=-1;
            }
        }
        return ans;
        
    }
};