class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=0;
        int ans;
        int n=nums.size();
        unordered_set<int> s;
        for(auto num:nums) s.insert(num);
        for(int i=0;i<n;i++){
            if(i==0 || nums[i]==nums[i-1]+1) sum+=nums[i];
            else break;
        } 
        for(int i=sum;;i++){
            if(s.find(i)==s.end()){
                ans=i;
                break;
            }
        } 
        return ans;      
    }
};