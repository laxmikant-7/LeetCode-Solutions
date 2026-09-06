class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        long long first_half=0;
        long long second_half=0;
        for(int i=0;i<n;i++){
            if(i<(n/2)){
                first_half+=nums[i];
            }
            else{
                second_half+=nums[i];
            }
        }
        int l=0,r=n/2;
        int good_no=(first_half!=second_half) ? 1:0;
        while(l<((n/2))-1){
            first_half=first_half-nums[l]+nums[r];
            second_half=second_half+nums[l]-nums[r];
            if(first_half!=second_half) good_no++;
            l++;
            r++;
        }
        return good_no;
    }
};