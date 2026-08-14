class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        vector<int>freq(26,0);
        int max_len=0;
        while(j<n){
            char ch=s[j];
            int idx=ch-'a';
            freq[idx]++;
            while(freq[idx]>2){
                freq[s[i]-'a']--;
                i++;
            }
            max_len=max(max_len,j-i+1);
            j++;
        }
        return max_len;
    }
};