class Solution {
public:
    bool safe(vector<vector<char>>& board,int i,int j,int num){
        //row check
        for(int col=0;col<9;col++){
            if(col!=j && board[i][col]==num) return false;
        }
        //col check
        for(int row=0;row<9;row++){
            if(row!=i && board[row][j]==num) return false;
        }
        //cell check
        int x,y;
        if(i<=2) x=0;
        else if(i<=5) x=3;
        else x=6;

        if(j<=2) y=0;
        else if(j<=5) y=3;
        else y=6;

        for(int idx1=x;idx1<x+3;idx1++){
            for(int idx2=y;idx2<y+3;idx2++){
                if(idx1!=i && idx2!=j && board[idx1][idx2]==num) return false;
            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=9;
        for(int i=0;i<n;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.' && !safe(board,i,j,board[i][j])) return false;
            }
        }
        return true;
    }
};