class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int m=tri.size();
        vector<int> dp=tri[0];
        for(int i=1;i<m;i++){
            vector<int> temp;
            for(int j=0;j<tri[i].size();j++){
        
                    int up=INT_MAX;
                    int left=INT_MAX;
                    if(j<dp.size()) up=dp[j];
                    if(j!=0) left=dp[j-1];
                    int mini=tri[i][j]+min(up,left);
                    temp.push_back(mini);
            }
            dp=temp;
        }
        auto it=min_element(dp.begin(),dp.end());
        return *it;
    }
};