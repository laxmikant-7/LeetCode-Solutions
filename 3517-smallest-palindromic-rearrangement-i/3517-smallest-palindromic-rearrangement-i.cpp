class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;
        vector<int> temp(26,0);
        for(int i=0;i<(n/2);i++){
            temp[s[i]-'a']+=1;
        }
        string ans1;
        for(int i=0;i<26;i++){
            int f=temp[i];
            while(f--){
                ans1.push_back('a'+i);
            }
        }
        string ans=ans1;
        if(n%2==1){
            ans.push_back(s[(n/2)]);
        }
        reverse(ans1.begin(),ans1.end());
        ans+=ans1;
        return ans;
    }
};