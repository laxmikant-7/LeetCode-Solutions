class Solution {
public:
    string addBinary(string a, string b) {
        int m=a.size()-1;
        int n=b.size()-1;
        int c=0;
        string ans="";
        while(m>=0 || n>=0){
            int sum=c;
            if(m>=0) sum+=a[m--]-'0';
            if(n>=0) sum+=b[n--]-'0';
            c=sum>1?1:0;
            ans+=to_string(sum%2);
        }
        if(c!0) ans+=to_string(c);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};