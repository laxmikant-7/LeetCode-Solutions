class Solution {
public:
    bool valid(int i,int j,int m,int n){
        if(i<0 || j<0 || i>=m || j>=n) return false;
        return true;
    }
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) temp[0]=1;
                else{
                    int up=(valid(i-1,j,m,n))?prev[j]:0;
                    int left=(valid(i,j-1,m,n))?temp[j-1]:0;
                    temp[j]=up+left;
                }
            }
            swap(temp,prev);
        }
        return prev[n-1];
    }
};