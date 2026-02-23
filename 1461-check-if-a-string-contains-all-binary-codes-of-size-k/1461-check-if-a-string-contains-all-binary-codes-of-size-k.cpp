class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size()<k) return false;
        unordered_set<string> st;
        int req_size=pow(2,k);
        for(int i=0;i<=s.size()-k;i++){
            st.insert(s.substr(i,k));
            if(st.size()==req_size) break;
        }
        return st.size()==req_size;
    }
};