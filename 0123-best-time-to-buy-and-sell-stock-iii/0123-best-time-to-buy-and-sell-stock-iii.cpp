class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1 || (n==2 && prices[0]>=prices[1])) return 0;
        vector<int> ltor(n);
        vector<int> rtol(n);
        int mini=0;
        int maxi1=0;
        ltor[0]=0;
        rtol[n-1]=0;
        for(int i=1;i<n;i++){
            int profit=prices[i]-prices[mini];
            if(profit>maxi1){
                maxi1=profit;
            }
            ltor[i]=maxi1;
            if(prices[i]<prices[mini]){
                mini=i;
            }
        }
        int maxi2=0;
        int maxiidx=n-1;
        for(int i=n-2;i>=0;i--){
            int profit=prices[maxiidx]-prices[i];
            if(profit>maxi2){
                maxi2=profit;
            }
            rtol[i]=maxi2;
            if(prices[i]>prices[maxiidx]){
                maxiidx=i;
            }
        }
        int ans = ltor[n-1];

        vector<int> suffixMax(n);
suffixMax[n-1] = rtol[n-1];

// build suffix max
for(int i = n-2; i >= 0; i--) {
    suffixMax[i] = max(rtol[i], suffixMax[i+1]);
}



// compute answer
for(int i = 0; i < n-1; i++) {
    ans = max(ans, ltor[i] + suffixMax[i+1]);
}
        return ans;
    }
};