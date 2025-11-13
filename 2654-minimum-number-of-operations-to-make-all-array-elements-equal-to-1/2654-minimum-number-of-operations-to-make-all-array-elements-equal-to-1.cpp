class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int one_count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) one_count++;
        }
        if(one_count!=0) return n-one_count;
        int min_op=INT_MAX;
        for(int i=0;i<n-1;i++){
            int g=nums[i];
           for(int j=i+1;j<n;j++){
            g=gcd(g,nums[j]);
            if(g==1){
                min_op=min(min_op,j-i);
                break;
            }
           }
        }
        if(min_op==INT_MAX) return -1;

        return min_op+(n-1);
    }
};