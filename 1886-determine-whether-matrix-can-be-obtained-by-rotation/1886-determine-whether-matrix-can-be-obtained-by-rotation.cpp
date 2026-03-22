class Solution {
public:
    void rotate(vector<vector<int>> &temp,int idx1,int idx2,vector<vector<int>> &mat){
        int n=mat.size();
        for(int i=0;i<n;i++){
            idx2--;
            for(int j=0;j<n;j++){
                temp[i][j]=mat[j][idx2];
            }
        }
    }
    bool issame(vector<vector<int>> &target,vector<vector<int>> &mat){
        int n=target.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(target[i][j]!=mat[i][j]) return false;
            }
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        for(int k=0;k<4;k++){
            vector<vector<int>> temp=mat;
            rotate(temp,0,n,mat);
            mat=temp;
            if(issame(target,mat)) return true;
        }
        return false;
    }
};