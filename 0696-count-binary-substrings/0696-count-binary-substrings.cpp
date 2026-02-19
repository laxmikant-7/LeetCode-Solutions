class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.size();
        int curr=1;
        int prev=0;
        int count=0;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) curr++;
            else{
                count+=min(curr,prev);
                prev=curr;
                curr=1;
            }
        }
        return count+min(curr,prev);
    }
};