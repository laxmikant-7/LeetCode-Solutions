class Solution {
public:
    void find_all_subsets(vector<int>& nums,vector<vector<int>> &ans,vector<int> &temp,int i){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        find_all_subsets(nums,ans,temp,i+1);
        temp.pop_back();
        find_all_subsets(nums,ans,temp,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        find_all_subsets(nums,ans,temp,0);
        return ans;
    }
};