class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for(int i=0;i<4;i++){
            if(i<2 && s1[i]!=s2[i] && s1[i]!=s2[i+2]) return false;
            if(i>=2 && s1[i]!=s2[i] && s1[i]!=s2[i+2] && s1[i]!=s2[i-2]) return false;
        }
        return true;
    }
};