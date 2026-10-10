class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        int k=k1+k2;
        vector<int> diffcnt(1e5+1,0);
        for(int i=0;i<n;i++){
            int d=abs(nums1[i]-nums2[i]);
            diffcnt[d]++;
        }
        for(int i=1e5;i>0 && k>0;i--){
            int avai_op=min(k,diffcnt[i]);
            k-=avai_op;
            diffcnt[i]-=avai_op;
            diffcnt[i-1]+=avai_op;
        }
        long long ans=0;
        for(int i=1e5;i>0;i--){
            ans+=(1LL*diffcnt[i]*i*i);
        }
        return ans;
    }
};