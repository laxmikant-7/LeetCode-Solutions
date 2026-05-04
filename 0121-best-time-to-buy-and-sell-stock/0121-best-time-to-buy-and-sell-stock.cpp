class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p=INT_MIN;
        int n=prices.size();
        int bb=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]>=bb){
                p=max(p,prices[i]-bb);
            }
            else{
                bb=prices[i];
            }
        }
        return (p==INT_MIN)?0:p;
    }
};