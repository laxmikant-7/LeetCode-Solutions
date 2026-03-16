class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(int num:nums){
            m[num]++;
        }
        for(int i=0;i<n;i++){
            if(m[nums[i]]==1 && nums[i]%2==0) return nums[i];
        }
        return -1;
    }
};