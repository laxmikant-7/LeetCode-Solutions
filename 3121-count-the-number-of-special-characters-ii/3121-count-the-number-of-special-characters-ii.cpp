class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        unordered_map<char,int> m;
        unordered_map<char,int> m1;

        for(int i=0;i<n;i++){
            char ch=word[i];
            if(ch>='A' && ch<='Z' && m.find(ch)==m.end()) m[ch]=i;
        }
        for(int i=0;i<n;i++){
            char ch=word[i];
            if(ch>='a' && ch<='z') m1[ch]=i;
        }
        int c=0;
        for(auto ch:m1){
                char u=ch.first-32;
                if(m.count(u) && m[u]>m1[u+32]){
                    c++;
                    m.erase(u);
                }
                
        }
        return c;
    }
};