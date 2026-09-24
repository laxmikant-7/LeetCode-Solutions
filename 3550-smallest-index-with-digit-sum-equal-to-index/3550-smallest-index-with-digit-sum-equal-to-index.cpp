class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int num=nums[i];
            int temp=0;
            while(num>0){
                int d=num%10;
                temp+=d;
                num/=10;
            }
            if(temp==i) return i;
        }
        return -1;
    }
};