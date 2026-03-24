class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mod=12345;
        vector<vector<int>> p(n,vector<int>(m));
        vector<vector<int>> suffix(n,vector<int>(m));
        long long suff=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                suffix[i][j]=suff;
                suff=(suff*grid[i][j])%mod;
            }
        }
        long long pre=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                p[i][j]=(pre*suffix[i][j])%mod;
                pre=(pre*grid[i][j])%mod;
            }
        }
        return p;
    }
};