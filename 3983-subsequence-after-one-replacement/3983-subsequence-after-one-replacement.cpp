class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(n>m) return false;
        int i=0,j=0;
        char prev='-';
        while(i<n&&j<m){
            if(s[i]!=t[j]){
                if(prev=='-'){
                    prev=s[i];
                    s[i]=t[j];
                    i++;
                    j++;
                }else if(prev==t[j]){
                    prev='-';
                    j++;
                }else{
                    j++;
                }
            }else{
                i++;
                j++;
            }
        }
        return i==n;
    }
};