class Solution {
public:
    int M=1e9+7;
    int dp[201][201][201];
    long long solve(int i,int seq1,int seq2,vector<int>& nums){
        if(i==nums.size()){
            return (seq1!=0 && seq2!=0 && seq1==seq2)?1:0;
        }
        if(dp[i][seq1][seq2]!=-1) return dp[i][seq1][seq2];

        long long skip=solve(i+1,seq1,seq2,nums);
        long long take1=(seq1==0)?solve(i+1,nums[i],seq2,nums):solve(i+1,gcd(seq1,nums[i]),seq2,nums);
        long long take2=(seq2==0)?solve(i+1,seq1,nums[i],nums):solve(i+1,seq1,gcd(seq2,nums[i]),nums);

        return dp[i][seq1][seq2]=(skip+take1+take2)%M;

    }
    

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return (int)solve(0,0,0,nums);
    }
};