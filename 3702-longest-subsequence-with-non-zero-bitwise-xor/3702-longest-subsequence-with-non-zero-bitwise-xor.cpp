class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int zero_count=0;
        int ans_xor=0;
        for(int num:nums){
            if(num==0) zero_count++;
            ans_xor^=num;
        }
        if(ans_xor!=0) return n;
        else if(zero_count==n) return 0;
        return n-1;
    }
};