class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int m=tri.size();
        vector<vector<int>> dp;
        for(int i=0;i<m;i++){
            vector<int> temp;
            for(int j=0;j<tri[i].size();j++){
                if(i==0 && j==0) temp.push_back(tri[0][0]);
                else{
                    int up=INT_MAX;
                    int left=INT_MAX;
                    if(i>0 && j < dp[i-1].size()) up=dp[i-1][j];
                    if(i>0 && j>0) left=dp[i-1][j-1];
                    int mini=tri[i][j]+min(up,left);
                    temp.push_back(mini);
                }
            }
            dp.push_back(temp);
        }
        auto it=min_element(dp[m-1].begin(),dp[m-1].end());
        return *it;
    }
};