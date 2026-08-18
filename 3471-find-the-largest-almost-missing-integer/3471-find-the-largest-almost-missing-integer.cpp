class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(auto num:nums) m[num]++;
        if(k==1){
            sort(nums.begin(),nums.end());
            for(int i=n-1;i>=0;i--){
                if(m[nums[i]]==1) return nums[i];
            }
            return -1;
        }
        else if(k==n) {
            int maxi=*max_element(nums.begin(),nums.end());
            return maxi;
        }
        else{
            int temp1=nums[0];
            int temp2=nums[n-1];
            if(temp1==temp2) return -1;
            int freq1=m[temp1];
            int freq2=m[temp2];
            if(freq1==1 && freq2==1) return max(temp1,temp2);
            else if(freq1>1 || freq2>1){
                if(freq1>1 && freq2>1) return -1;
                else if(freq1>1) return temp2;
                return temp1;
            }
        }
        return -1;
    }
};