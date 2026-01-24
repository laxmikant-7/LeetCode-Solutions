class Solution {
public:

    bool possible(vector<int> nums,int t,int mid){
        int sum=0;
        for(auto num:nums){
            sum+=ceil((1.0*num)/mid);
        }
        return sum<=t;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(nums,threshold,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};