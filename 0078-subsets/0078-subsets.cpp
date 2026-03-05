class Solution {
public:
    bool isSetBit(int n,int i){
        return (n&(1<<i));
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        int subsets=1<<n;
        for(int i=0;i<subsets;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                if(isSetBit(i,j)){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};