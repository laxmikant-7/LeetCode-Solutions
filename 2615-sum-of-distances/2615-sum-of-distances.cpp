class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,long long> tsum;
        unordered_map<int,int> tcount;
        vector<long long> ans(n);

        vector<long long> presum(n);
        vector<int> precount(n);
        for(int i=0;i<n;i++){
            presum[i]=(tsum.find(nums[i])!=tsum.end())?tsum[nums[i]]:1LL*0;
            precount[i]=(tcount.find(nums[i])!=tcount.end())?tcount[nums[i]]:0;
            tsum[nums[i]]+=1LL*i;
            tcount[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            int lcount=precount[i];
            int rcount=tcount[nums[i]]-(lcount+1);
            long long lsum=presum[i];
            long long rsum=tsum[nums[i]]-(presum[i]+i);
            ans[i]=abs((1LL*lcount*i)-lsum)+abs((1LL*rcount*i)-rsum);
        }
        return ans;
    }
};