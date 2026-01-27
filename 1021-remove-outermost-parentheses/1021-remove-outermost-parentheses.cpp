class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int count=0;
        for(char c:s){
            count+=(c=='(') ? 1:-1;
            if(c=='(' && count>1){
                ans+='(';
            }
            else if(c==')' && count>0){
                ans+=')';
            }
        }
        return ans;
    }
};