class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> s;
        int c=0;
        for(auto ch:word) s.insert(ch);
        for(auto ch:s){
            if(ch>='a' && ch<='z'){
                char upper=ch-32;
                if(s.count(upper)) c++;
            }
            else{
                char lower=ch+32;
                if(s.count(lower)) c++;
            }
        }
        return c/2;
    }
};