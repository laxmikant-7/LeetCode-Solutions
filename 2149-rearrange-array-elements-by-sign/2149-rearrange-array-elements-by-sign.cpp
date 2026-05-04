class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int s=nums.size();
        vector<int> p;
        vector<int> n;
        for(int i=0;i<s;i++){
            if(nums[i]>0) p.push_back(nums[i]);
            else n.push_back(nums[i]); 
        }
        int idx=0;
        for(int i=0;i<s/2;i++){
            nums[idx]=p[i];
            nums[idx+1]=n[i];
            idx+=2;
        }
        return nums;

    }
};