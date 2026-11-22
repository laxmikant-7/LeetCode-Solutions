class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int k=0;
        for(int j=0;j<n;j++){
            if(nums[j]==nums[i] && i!=j){
                nums[j]=101;
            }
            else{
                i=j;
                k++;
            }
        }
        sort(nums.begin(),nums.end());
        return k;
        
    }
};