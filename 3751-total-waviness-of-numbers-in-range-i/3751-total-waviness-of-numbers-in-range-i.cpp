class Solution {
public:
    int find(int n){
        string s=to_string(n);
        int sz=s.size();
        int c=0;
        for(int i=1;i<sz-1;i++){
            if(((s[i-1]<s[i]) && (s[i]>s[i+1])) || ((s[i-1]>s[i]) && (s[i]<s[i+1]))) c++;
        }
        return c;
    }
    int totalWaviness(int num1, int num2) {
        int count=0;
        for(int i=num1;i<=num2;i++){
            int d=log10(i)+1;
            if(d>=3){
                count+=find(i);
            }
        }
        return count;
    }
};