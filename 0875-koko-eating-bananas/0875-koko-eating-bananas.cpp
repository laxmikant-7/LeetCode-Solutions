class Solution {
public:
    long long find(vector<int>& piles, int n){
        long long time=0;
        for(auto p:piles){
            time += (p + n - 1) / n;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int t) {
        int h=*max_element(piles.begin(),piles.end());
        int l=1;
        while(l<=h){
            int mid=l+(h-l)/2;
            long long time=find(piles,mid);
            if(time<=t){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};