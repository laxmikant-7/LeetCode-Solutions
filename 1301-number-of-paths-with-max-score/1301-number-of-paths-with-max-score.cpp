class Solution {
public:
    const int MOD = 1000000007;
    // void solve(int i,int j,vector<string>& b,unordered_map<int,int> &m,int sum,vector<vector<vector<int>>> &dp){
    //     if(i==0 && j==0){
    //         m[sum]++;
    //         m[sum] %= MOD;
    //         return;
    //     }
    //     if()
    //     int dx[]={0,-1,-1};
    //     int dy[]={-1,-1,0};
    //     for(int k=0;k<3;k++){
    //         int ni=i+dx[k];
    //         int nj=j+dy[k];
    //         int n=b.size();
    //         if(ni>=0 && ni<n && nj>=0 && nj<n && b[ni][nj]!='X'){
    //             int val=0;
    //             if(b[ni][nj]!='E' && b[ni][nj]!='s') val=b[ni][nj]-'0';
    //             solve(ni,nj,b,m,sum+val);
               
    //         }
    //     }
    //     return;
    // }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        // unordered_map<int,int> m;
        // vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(90000,-1)));

        // solve(n-1,n-1,board,m,0,dp);
        // int maxi=INT_MIN;
        // for(auto it:m){
        //     maxi=max(maxi,it.first);
        // }
        // if(maxi==INT_MIN) return {0,0};
        // return {maxi,m[maxi]};
        int dx[]={0,1,1};
        int dy[]={1,1,0};
        vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,{-1,0}));
        dp[n-1][n-1]={0,1};
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(board[i][j]=='X') continue;
                if(board[i][j]=='S') continue;
                int bscore=INT_MIN;
                for(int k=0;k<3;k++){
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    if(ni>=0 && ni<n && nj>=0 && nj<n) bscore=max(bscore,dp[ni][nj].first);
                }
                int f=0;
                for(int k=0;k<3;k++){
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    if(ni>=0 && ni<n && nj>=0 && nj<n && dp[ni][nj].first==bscore) f=(f+dp[ni][nj].second)%MOD;
                }
                if(board[i][j]=='E'){
                    dp[i][j]={bscore,f};
                }else{
                    dp[i][j]={bscore+(board[i][j]-'0'),f};
                }
            }
        }
        if(dp[0][0].second==0) return{0,0};



        return {dp[0][0].first,dp[0][0].second};
    }
};