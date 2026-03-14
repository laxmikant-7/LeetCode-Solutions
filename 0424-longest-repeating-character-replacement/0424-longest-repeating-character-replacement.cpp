class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0;
        int maxlen=0;
        int maxfreq=0;
        vector<int> freq(26,0);
        for(int j=0;j<n;j++){
            freq[s[j]-'A']++;
            maxfreq=max(maxfreq,freq[s[j]-'A']);

            if((j-i+1)-maxfreq>k){
                freq[s[i]-'A']--;
                maxfreq=max(maxfreq,freq[i]);
                i++;
            }

            maxlen=max(maxlen,j-i+1);
        }  
        return maxlen;
    }
};