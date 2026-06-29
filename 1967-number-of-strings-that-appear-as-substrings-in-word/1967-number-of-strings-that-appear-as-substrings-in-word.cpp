class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n=word.size();
        unordered_map<string,int> m;
        int ans=0;
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=i;j<n;j++){
                temp+=word[j];
                m[temp]++;
            }
        }
        for(auto s:patterns){
            if(m.find(s)!=m.end()) ans++;
        }
        return ans;
    }
};