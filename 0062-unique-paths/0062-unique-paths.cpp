class Solution {
public:
    // int find(int i,int j,int m,int n,vector<vector<int>> &dp){
    //     if(i>=m || j>=n) return 0;
    //     if(i==m-1 && j==n-1) return 1;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int right=find(i,j+1,m,n,dp);
    //     int down=find(i+1,j,m,n,dp);
    //     return dp[i][j]=right+down;
    // }
    int uniquePaths(int m, int n) {
        vector<int> pre(n,0);
        
        for(int i=m-1;i>=0;i--){
            vector<int> temp(n,0);
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1) temp[j]=1;
                else{
                    int r=0;
                    int l=0;
                    if(j+1<n) r=temp[j+1];
                    if(i+1<m) l=pre[j];
                    temp[j]=r+l;
                }
            }
            pre=temp;
        }
        return pre[0];
    }
};