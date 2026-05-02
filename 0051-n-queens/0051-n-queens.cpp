class Solution {
public:    
    bool safe(int i,int j,vector<string> &v,int n){
        for(int col=0;col<j;col++){
            if(v[i][col]=='Q') return false;
        }

        int row=i-1;
        int col=j-1;
        while(row>=0 && col>=0){
            if(v[row][col]=='Q') return false;
            row--;
            col--;
        }

        row=i+1;
        col=j-1;
        while(row<n && col>=0){
            if(v[row][col]=='Q') return false;
            row++;
            col--;
        }

        return true;
    }
    void solve(vector<string> &v,vector<vector<string>> &ans,int col,int n){
        if(col==n){
            ans.push_back(v);
            return;
        }
        for(int row=0;row<n;row++){
            if(safe(row,col,v,n)){
                v[row][col]='Q';
                solve(v,ans,col+1,n);
                v[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> v(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(v,ans,0,n);
        return ans;
    }
};