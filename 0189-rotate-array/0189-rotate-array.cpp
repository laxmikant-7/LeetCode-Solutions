class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        if(k==0) return;
        vector<int> temp;
        int idx=n-k;
        for(int i=0;i<n;i++){
            temp.push_back(nums[(idx+i)%n]);
        }
        for(int i=0;i<n;i++){
            nums[i]=temp[i];
        }
        return;
    }
};