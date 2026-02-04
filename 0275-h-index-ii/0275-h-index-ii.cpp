class Solution {
public:
    int hIndex(vector<int>& c) {
        if(c.size()==1){
            if(c[0]==0){
                return 0;
            }
            return 1;
        }
        int left=0;
        int right = c.size()-1;
        int ans=0;
        int n = c.size();
        while(left<=right){
            int mid = left + (right-left)/2;
            int h = n-mid;
            if(c[mid]>=h){
                ans=h;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};