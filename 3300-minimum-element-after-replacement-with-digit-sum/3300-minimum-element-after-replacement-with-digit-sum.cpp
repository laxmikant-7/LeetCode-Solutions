class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int num=0;
            int temp=nums[i];
            while(temp>0){
                int d=temp%10;
                num+=d;
                temp/=10;
            }
            mini=min(mini,num);
        }
        return mini;
    }
};