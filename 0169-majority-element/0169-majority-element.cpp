class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || n==2) return nums[0];
        int count=0;
        int element=nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]==element) count++;
            else{
                count--;
                if(count==0) element=nums[i+1];
            }
        }
        return element;
    }
};