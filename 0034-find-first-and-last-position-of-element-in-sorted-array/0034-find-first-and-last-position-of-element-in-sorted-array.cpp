class Solution {
public:

    int findFirstIdx(int low,int high,vector<int> &nums,int target){
        if(low>high){
            return low;
        }
        int mid=low+(high-low)/2;
        if(nums[mid]>=target){
            return findFirstIdx(low,mid-1,nums,target);
        }
        else{
            return findFirstIdx(mid+1,high,nums,target);
        }
    }
    int findLastIdx(int low,int high,vector<int> &nums,int target){
        if(low>high){
            return low;
        }
        int mid=low+(high-low)/2;
        if(nums[mid]>target){
            return findLastIdx(low,mid-1,nums,target);
        }
        else{
            return findLastIdx(mid+1,high,nums,target);
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0) return {-1,-1};
        int f_idx=findFirstIdx(0,n-1,nums,target);
        if(f_idx==n||nums[f_idx]!=target) return {-1,-1};
        int l_idx=findLastIdx(f_idx,n-1,nums,target);
        return {f_idx,l_idx-1};
    }
};