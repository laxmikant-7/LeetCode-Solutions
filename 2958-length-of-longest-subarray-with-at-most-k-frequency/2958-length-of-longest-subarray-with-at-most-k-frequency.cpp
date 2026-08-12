class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int n=nums.size();
        int max_len=INT_MIN;
        int i=0;
        int j=0;
        while(j<n){
            m[nums[j]]++;
            while(m[nums[j]]>k){
                m[nums[i]]--;
                i++;
            }
            max_len=max(max_len,j-i+1);
            j++;
        }
        return max_len;
    }
};