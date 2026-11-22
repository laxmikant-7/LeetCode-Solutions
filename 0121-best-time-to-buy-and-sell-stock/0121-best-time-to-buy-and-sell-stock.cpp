class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        int bb=p[0];
        if(n==0) return 0;
        int ans=INT_MIN;
        for(int i=1;i<n;i++){
            int cp=p[i]-bb;
            ans=max(ans,cp);
            bb=min(bb,p[i]);
        }
        return (ans<0)?0:ans;
    }
};