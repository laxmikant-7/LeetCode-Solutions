class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int i=0,j=n-1;
        long long ans=0;
        while(i<=j){
            int num1=nums[i];
            int num2=nums[j];
            if(i==j) ans+=(1LL*num1*num1);
            else{
                ans+=(1LL*num2*num2);
                ans-=(1LL*num1*num1);
            }
            i++;
            j--;
        }
        return ans;
    }
};