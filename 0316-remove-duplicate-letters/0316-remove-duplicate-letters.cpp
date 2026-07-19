class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        vector<bool> seen(26,false);
        string ans="";
        vector<int> last(26,0);
        for(int i=0;i<n;i++){
            last[s[i]-'a']=i;
        }
        for(int i=0;i<n;i++){
            if(seen[s[i]-'a']) continue;

            while(ans.size()>0 && ans.back()>s[i] && last[ans.back()-'a']>i){
                seen[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans+=s[i];
            seen[s[i]-'a']=true;

        }
        return ans;
    }
};