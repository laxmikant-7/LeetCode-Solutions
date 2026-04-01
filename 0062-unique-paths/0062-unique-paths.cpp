class Solution {
public:
    bool valid(int i,int j,int m,int n){
        if(i<0 || j<0 || i>=m || j>=n) return false;
        return true;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue;
                else{
                    int up=(valid(i-1,j,m,n))?dp[i-1][j]:0;
                    int left=(valid(i,j-1,m,n))?dp[i][j-1]:0;
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};