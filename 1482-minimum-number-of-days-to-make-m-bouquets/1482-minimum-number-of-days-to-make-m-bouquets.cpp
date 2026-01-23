class Solution {
public:


    bool possible(vector<int> bloomDay,int day,int m,int k){
        int count=0;
        int nob=0;
        for(auto bloom:bloomDay){
            if(bloom<=day){
                count++;
            }
            else{
               nob+=count/k;
               count=0;
            }
        }
        nob+=count/k;
        return (nob>=m)?true:false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n<1LL*m*k) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(bloomDay,mid,m,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};