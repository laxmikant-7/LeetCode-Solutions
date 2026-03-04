class Solution {
public:
    bool colValid(int row,int j,vector<vector<int>>& mat){
        int cnt=0;
        for(int i=0;i<row;i++){
            if(mat[i][j]==1)cnt++;
            if(cnt>1) return false;
        }
        return true;
    }
    bool rowValid(int col,int i,vector<vector<int>>& mat){
        int cnt=0;
        for(int j=0;j<col;j++){
            if(mat[i][j]==1)cnt++;
            if(cnt>1) return false;
        }
        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1 && colValid(m,j,mat) && rowValid(n,i,mat)) cnt++;
            }
        }
        return cnt;
    }
};