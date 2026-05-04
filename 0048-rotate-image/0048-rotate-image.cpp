class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<vector<int>> temp(n,vector<int>(n));
        int y=n-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[j][y]=mat[i][j];
            }
            y--;
        }
        mat=temp;
        return;
    }
};