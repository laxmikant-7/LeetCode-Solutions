class Solution {
public:
    void rotate(vector<int>& nums, int d) {
        int n=nums.size();
        vector<int> r(n);
        int x=n-(d%n);
        for(int i=0;i<n;i++){
            r[i]=nums[(i+x)%n];
        }
        nums=r;
        return;
    }
};
   