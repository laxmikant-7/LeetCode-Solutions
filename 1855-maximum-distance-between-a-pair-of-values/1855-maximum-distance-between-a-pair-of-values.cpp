class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int ans=0;
        for(int i=0;i<n1;i++){
            int l=i,r=n2-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(nums2[mid]<nums1[i]){
                    r=mid-1;
                }
                else{
                    ans=max(ans,mid-i);
                    l=mid+1;
                }
            }
        }
        return ans;
    }
};