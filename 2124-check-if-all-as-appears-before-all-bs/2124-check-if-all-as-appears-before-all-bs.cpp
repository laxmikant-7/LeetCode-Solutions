class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        int i=0;
        while(i<n && s[i]=='a'){
            i++;
        }
        while(i<n){
            if(s[i++]=='a') return false;
        }
        return true;
    }
};