class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        int dip=1;
        int i=1;
        for(;i<n;i++){
            if(nums[i]<nums[i-1]) {
                dip=i;
                break;
            }
        }
        if(i==n) return true;
        for(int i=0;i<n-1;i++){
            if(nums[dip%n]>nums[(dip+1)%n]) return false;
            else{
                dip+=1;
            }
        }
        return true;
    }
    };
