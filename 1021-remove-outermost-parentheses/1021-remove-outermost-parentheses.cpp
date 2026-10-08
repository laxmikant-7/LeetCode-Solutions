class Solution {
public:
    string removeOuterParentheses(string s) {
        int x=0;
        string ans="";
        for(auto ch:s){
            bool add=true;
           if((x==0 && ch=='(') || (x==1 && ch==')')) add=false;

           if(ch=='(') x++;
           else x--;

           if(add) ans.push_back(ch);
        }
        return ans;
    }
};