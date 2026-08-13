class Solution {
public:
    double minPrice(vector<int>& p, vector<int>& d) {
        sort(p.begin(),p.end());
        sort(d.begin(),d.end());
        double ans=0;
        int i=p.size()-1;
        int j=d.size()-1;
        while(i>=0 && j>=0){
            double temp=(p[i]*(100-d[j]))/100.0;
            ans+=temp;
            i--;
            j--;
        }
        while(i>=0){
            ans+=(double)p[i];
            i--;
        }
        return ans;
    }
};