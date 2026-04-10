class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int dist=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i!=j && i!=k && j!=k){
                        if(nums[i]==nums[j] && nums[j]==nums[k]){
                            dist=min(dist,abs(i - j) + abs(j - k) + abs(k - i));
                        }
                    }
                }
            }
        }
        return (dist==INT_MAX)?-1:dist;
    }
};