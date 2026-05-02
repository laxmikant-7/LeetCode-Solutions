class Solution {
public:
    bool solve(vector<vector<char>>& b, string w,int i,int j,int idx){
        if(idx==w.size()) return true;
        if(i<0 || i>=b.size() || j<0 || j>=b[0].size() || b[i][j]!=w[idx]) return false;
        char temp=b[i][j];
        b[i][j]='#';
        bool found=(solve(b,w,i-1,j,idx+1) || solve(b,w,i,j+1,idx+1) || solve(b,w,i+1,j,idx+1) || solve(b,w,i,j-1,idx+1));
        b[i][j]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& b, string w) {
        int n=b.size();
        int m=b[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[i][j]==w[0]){
                    if(solve(b,w,i,j,0)) return true;
                }
            }
        }
        return false;
    }
};