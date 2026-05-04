class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=INT_MIN;
        vector<long long> presum(n,0);
        for(int i=1;i<n;i++){
            presum[i]=presum[i-1]+1LL*nums[i-1];
        }
        for(int i=0;i<n;i++){
            int t=nums[i];
            int l=0;
            int r=i;
            while(l<=r && r>=0 && l<=i){
                int mid=l+(r-l)/2;
                int count=i-mid+1;
                long long realsum=1LL*t+presum[i]-presum[mid];
                long long needsum=1LL*t*count;
                long long op=needsum-realsum;
                if(op<=1LL*k){
                    ans=max(ans,i-mid+1);
                    r=mid-1;
                }
                else l=mid+1;
            }
        }
        return ans;
    }
};