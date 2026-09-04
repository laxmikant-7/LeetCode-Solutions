class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> temp1(n);
        vector<int> temp2(n);
        temp1[0]=nums[0];
        temp2[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            temp1[i]=max(temp1[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            temp2[i]=min(temp2[i+1],nums[i]);
        }
        int i=0;
        for(;i<n;i++){
            int score=temp1[i]-temp2[i];
            if(score<=k) break;
        }
        return (i<n)?i:-1;
    }
};