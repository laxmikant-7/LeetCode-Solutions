class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<long long> hsum(n,0);
        vector<long long> vsum(m,0);
        long long totalhsum=0;
        long long totalvsum=0;
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=0;j<m;j++){
                sum+=(long long)grid[i][j];
            }
            hsum[i]=sum;
            totalhsum+=sum;
        }
        long long sec1=0;
        for(auto it:hsum){
            sec1+=it;
            totalhsum-=it;
            if(sec1==totalhsum) return true;
        }
        for(int i=0;i<m;i++){
            long long sum=0;
            for(int j=0;j<n;j++){
                sum+=(long long)grid[j][i];
            }
            vsum[i]=sum;
            totalvsum+=sum;
        }
        sec1=0;
        for(auto it:vsum){
            sec1+=it;
            totalvsum-=it;
            if(sec1==totalvsum) return true;
        }
        return false;
    }
};