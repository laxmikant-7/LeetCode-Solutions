class Solution {
public:
    bool exist(vector<vector<char>>& mat,int r,int c,int sz){
        for(int i=r;i<r+sz;i++){
            for(int j=c;j<c+sz;j++){
                if(mat[i][j]=='0') return false;
            }
        }
        return true;

    }
    bool possible(vector<vector<char>>& mat,int sz){
        int r=mat.size();
        int c=mat[0].size();
        for(int i=0;i<=r-sz;i++){
            for(int j=0;j<=c-sz;j++){
                if(exist(mat,i,j,sz)) return true;
            }
        }
        return false;
    }
    int maximalSquare(vector<vector<char>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        int mxsz=min(r,c);
        int mnsz=0;
        int ans=0;
        while(mnsz<=mxsz){
            int mid=mnsz+(mxsz-mnsz)/2;
            if(possible(mat,mid)){
                ans=max(ans,mid);
                mnsz=mid+1;
            }
            else{
                mxsz=mid-1;
            }
        }
        return ans*ans;

        
    }
};