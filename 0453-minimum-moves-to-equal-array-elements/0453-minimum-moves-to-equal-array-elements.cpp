class Solution {
public:
    // bool solved(vector<int>& nums){
    //     int n=nums.size();
    //     bool ans=true;
    //     for(int num:nums){
    //         if(num!=nums[0]){
    //             ans=false;
    //             break;
    //         }
    //     }
    //     return ans;
    // }
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        //if(solved(nums)) return 0;
        int mini=*min_element(nums.begin(),nums.end());
        int ans=0;
        for(int num:nums){
            ans+=(num-mini);
        }
        return ans;
    }
};