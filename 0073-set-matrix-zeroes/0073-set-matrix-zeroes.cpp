class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> ans(matrix.begin(),matrix.end());

        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    for(int k=0;k<n;k++){
                        ans[i][k]=0;
                    }
                    for(int l=0;l<m;l++){
                        ans[l][j]=0;
                    }
                }
            }
        }
        matrix=ans;
        return;
    }
};