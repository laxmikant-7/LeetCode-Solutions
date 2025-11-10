class Solution {
public:
    void sortColors(vector<int>& nums) {
        int m=0,l=0,h=nums.size()-1;
        while(m<=h){
            if(nums[m]==1){
                m++;
            }
            else if(nums[m]==0){
                swap(nums[m],nums[l]);
                m++;
                l++;
            }
            else{
                swap(nums[m],nums[h]);
                h--;
            }
        }
        return;
    }
};