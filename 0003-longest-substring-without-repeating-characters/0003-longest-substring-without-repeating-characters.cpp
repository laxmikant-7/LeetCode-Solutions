class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0) return 0;
        unordered_set<char> st;
        int low=0;
        int ans=0;
        for(int high=0;high<n;){
            if(st.empty() || st.find(s[high])==st.end()){
                st.insert(s[high]);
                high++;
            }
            else{
                ans=max(ans,high-low);
                while(st.find(s[high])!=st.end()){
                st.erase(s[low]);
                low++;
                }
                st.insert(s[high]);
                high++;
            }

        }
        ans=max(ans,n-low);
        return ans;
    }
};
