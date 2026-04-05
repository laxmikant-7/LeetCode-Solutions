class Solution {
public:
    int solve(vector<int>& g, vector<int>& s, int i, int j){
        if(i == s.size() || j == g.size()) return 0;
        if(s[i] >= g[j]){
            return 1 + solve(g, s, i+1, j+1);
        }
        return solve(g, s, i+1, j);
    }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
       // vector<vector<int>> dp(s.size(),vector<int>(g.size(),-1));
        return solve(g,s,0,0);
        
    }
};