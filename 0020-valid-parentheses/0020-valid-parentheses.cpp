class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ch:s){
            if(ch=='(' || ch=='{' || ch=='[') {
                st.push(ch);
                continue;
            }
            else if(ch==')' && (st.empty() || st.top()!='(') || ch=='}' && (st.empty() || st.top()!='{') || ch==']' && (st.empty() || st.top()!='[')) return false;
            else st.pop();
        }
        return st.empty();
    }
};