class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int f=0;
        int ans=nums[0];
        for(int num:nums){
            if(num==ans) f++;
            else{
                f--;
                if(f==0){
                    ans=num;
                    f=1;
                }
            }
        }
        return ans;
    }
};