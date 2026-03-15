class Solution {
public:
    int find(vector<int>& nums, int k){
        int i=0;
        int total=0;
        int odds=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]&1) odds++;

            while(odds>k){
                if(nums[i]&1) odds--;
                i++;
            }

            total+=j-i+1;
        }
        return total;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n1=find(nums,k);
        int n2=find(nums,k-1);
        return n1-n2;
        
    }
};