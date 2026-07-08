class Solution {
public:
    typedef long long ll;
    int M=1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int> digits(n,0);
        vector<ll> sum(n,0);
        vector<ll> val(n,0);

        digits[0]=(s[0]-'0'!=0)?1:0;
        sum[0]=s[0]-'0';
        val[0]=s[0]-'0';

        for(int i=1;i<n;i++){
            int d=s[i]-'0';
            if(d!=0){
                digits[i]=digits[i-1]+1;
                sum[i]=(sum[i-1]+d)%M;
                val[i]=((val[i-1]*10)+d)%M;
            }
            else{
                digits[i]=digits[i-1];
                sum[i]=sum[i-1];
                val[i]=val[i-1];
            }
        }
        vector<ll> pow10(n + 1);
        pow10[0] = 1;

        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % M;
        }
        vector<int> ans(queries.size());
        int idx=0;
        for(auto &q:queries){
            int l=q[0];
            int r=q[1];
            if(l!=0){
                ll summ = (sum[r] - sum[l-1] + M) % M;
                int k=digits[r]-digits[l-1];
                ll x = (val[r] - (val[l-1] * pow10[k]) % M + M) % M;
               ans[idx++] = (int)((x * summ) % M);
            }
            else{
                ll summ=sum[r];
                ll x=val[r];
                ans[idx++] = (int)((x * summ) % M);
            }
        }

        return ans;
    }
};