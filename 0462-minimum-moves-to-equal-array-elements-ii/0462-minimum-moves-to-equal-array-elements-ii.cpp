class Solution {
public:

    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int moves=0;
        for(int i=0;i<(n/2);i++){
            moves+=abs(nums[i]-nums[n/2]);
            moves+=abs(nums[n-i-1]-nums[n/2]);
        }
        return moves;
    }
};