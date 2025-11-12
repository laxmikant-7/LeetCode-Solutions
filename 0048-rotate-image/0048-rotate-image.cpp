class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int x;
        vector<vector<int>> ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            x=m-1;
            for(int j=0;j<m;j++){
                ans[i][j]=mat[x][i];
                x--;
            }
        }
        mat=ans;
        return;
    }
};